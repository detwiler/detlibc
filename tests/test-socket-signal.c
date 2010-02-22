/*
 * Copyright (C) 2010  J. Michael Detwiler
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "system.h"

#include <det/socket_un.h>
#include <det/socket.h>
#include <det/signal.h>

#define MSG_MAX (1024)
#define BACKLOG (8)
#define TEST_SERVER "server.socket"
#define TEST_CLIENT "client.socket"

static int
server(int lfd)
{
  fd_set rset;

  FD_ZERO(&rset);
  FD_SET(lfd, &rset);

  char buf[MSG_MAX];
  memclr(buf, sizeof(buf));
  struct iovec iov[1];
  iov[0].iov_base = buf;
  iov[0].iov_len = sizeof(buf);

  while (true)
  {
    int s;

    if ((s = select((lfd + 1), &rset, NULL, NULL, NULL)) < 0)
      det_err_sys("select failure");

    int fd;

    if (FD_ISSET(lfd, &rset))
    {
      uid_t uid;

      if ((fd = det_serv_accept_un(lfd, &uid)) < 0)
        det_err_sys("accept failure");

      ssize_t n;

      if ((n = det_receive_message(fd, iov, num_elts(iov))) < 0)
      {
        det_err_sys("read error on fd %d", fd);
      }
      else if (n == 0)
      {
        det_err_msg("closed: fd %d", fd);
        close(fd);

        return (EXIT_FAILURE);
      }
      else
      {
        iov[0].iov_len = (size_t) n;

        for (int i = 0; i < n; i++)
          buf[i] = (char) toupper(buf[i]);

        if ((n = det_send_message(fd, iov, num_elts(iov))) < 0)
        {
          det_err_sys("send error on fd %d", fd);
        }
        else if (n == 0)
        {
          det_err_msg("closed: fd %d", fd);
          close(fd);

          return (EXIT_FAILURE);
        }
        else
        {
          return (EXIT_SUCCESS);
        }
      }
    }
  }

  return (EXIT_FAILURE);
} // server()

static int
client(int argc, char** argv)
{
  int fd;

  if ((fd = det_cli_conn_un(TEST_SERVER, TEST_CLIENT)) < 0)
    det_err_sys("connect failure");

  size_t n = 0;
  struct iovec iov[argc];

  for (int i = 0; i < argc; i++)
  {
    iov[i].iov_base = argv[i];
    n += iov[i].iov_len = (strlen(argv[i]) + 1);
  }

  ssize_t nsent;

  if ((nsent = det_send_message(fd, iov, num_elts(iov))) < 0)
    det_err_sys("send failure");

  assert((size_t) nsent == n);

  ssize_t nread;

  if ((nread = det_receive_message(fd, iov, num_elts(iov))) < 0)
    det_err_sys("receive failure");

  close(fd);

  assert((size_t) nread == n);

  for (size_t i = 0; i < num_elts(iov); i++)
    printf("%s\n", (char*) iov[i].iov_base);

  return (EXIT_SUCCESS);
} // client()

int
main(int argc, char** argv)
{
  det_signal_wait();

  pid_t pid;

  if ((pid = fork()) < 0)
  {
    det_err_sys("fork error");
  }
  else if (pid == 0)
  {
    det_wait_parent();

    return (client((argc - 1), &argv[1]));
  }
  else
  { 
    int lfd;

    if ((lfd = det_serv_listen_un(TEST_SERVER, BACKLOG)) < 0)
      det_err_sys("listen failure");

    det_signal_child(pid);

    if (server(lfd) != EXIT_SUCCESS)
      return (EXIT_FAILURE);

    pid_t child;
    int status;

    child = wait(&status);

    assert(child == pid);

    if (WIFEXITED(status))
      return (WEXITSTATUS(status));
  }

  return (EXIT_FAILURE);
} // main()
