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

#include <det/error.h>

int
main(int argc, char **argv)
{
  size_t size =  0;

  for (int i = 1; i < argc; i++)
    size += strlen(argv[i]);

  char buf[size + 1];
  memclr(buf, sizeof(buf));

  for (int i = 1; i < argc; i++)
    strcat(buf, argv[i]);

  det_err_msg("%s", buf);

  return (EXIT_SUCCESS);
} // main()
