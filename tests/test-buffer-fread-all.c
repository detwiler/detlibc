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

#include <det/buffer.h>

int
main(int argc, char **argv)
{
  struct det_buffer *buf = det_buffer_zalloc(0);

  if (argc > 1)
  {
    for (int i = 1; i < argc; i++)
    {
      FILE *file = fopen(argv[i], "r");

      if (!file)
        det_err_sys("Could not open file: %s", argv[i]);

      struct stat sb;

      fstat(fileno(file), &sb);

      ssize_t total = det_buffer_fread_all(buf, file);

      assert(total == sb.st_size);

      fwrite(det_buffer_get_data(buf), sizeof(uint8_t),
          (size_t) det_buffer_get_size(buf), stdout);

      fclose(file);

      det_buffer_clear(buf);
    }
  }
  else
  {
    ssize_t total = det_buffer_fread_all(buf, stdin);

    assert(total);

    fwrite(det_buffer_get_data(buf), sizeof(uint8_t),
        (size_t) det_buffer_get_size(buf), stdout);
  }

  det_buffer_free(buf);

  return (EXIT_SUCCESS);
} // main()
