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

#include <det/utils.h>

int
main(void)
{
  uint8_t data[64];
  char string[(sizeof(data) * 2) + 1];

  memset(data, 0xab, sizeof(data));

  if (det_data_to_hex(string, sizeof(string), data, sizeof(data)) !=
      (sizeof(string) - 1))
  {
    det_derr_msg("Failed det_data_to_hex");
    return (EXIT_FAILURE);
  }

  uint8_t buf[sizeof(data)];

  memclr(buf, sizeof(buf));

  if (det_hex_to_data(buf, sizeof(buf), string) != sizeof(data))
  {
    det_derr_msg("Failed det_hex_to_data");
    return (EXIT_FAILURE);
  }

  if (memcmp(data, buf, sizeof(data)))
  {
    det_derr_msg("Failed memcmp");
    return (EXIT_FAILURE);
  }

  return (EXIT_SUCCESS);
} // main()
