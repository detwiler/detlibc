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

#ifndef __DET_SOCKET_UN_H__
#define __DET_SOCKET_UN_H__ 1

#include <det/common.h>

__DET_BEGIN_C_DECLS__

#define DET_MAX_SUN_PATHLEN (92)

int
det_serv_listen_un(
    const char *name,
    int backlog
    ) DETLIB_EXPORT;

int
det_serv_accept_un(
    int listenfd,
    uid_t *uidptr
    ) DETLIB_EXPORT;

int
det_cli_conn_un(
    const char *server,
    const char *client
    ) DETLIB_EXPORT;

__DET_END_C_DECLS__

#endif /* !__DET_SOCKET_UN_H__ */
