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

ssize_t
det_data_to_hex(
    char * restrict hex,
    size_t hex_size,
    const void * restrict data,
    size_t data_size
    )
{
  ssize_t result = -1;

  if (unlikely(!data || !hex))
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    goto errout;
  }

  if (unlikely(!data_size || !hex_size))
  {
    errno = EINVAL;
    det_derr_ret("Invalid size");
    goto errout;
  }

  if (unlikely(((hex_size - 1) / 2) < data_size))
  {
    errno = EINVAL;
    det_derr_ret("hex_size not large enough");
    goto errout;
  }

  mpz_t mpz;
  mpz_init(mpz);

  mpz_import(mpz, data_size, 1, sizeof(uint8_t), 1, 0, data);

  result = gmp_snprintf(hex, hex_size, "%Zx", mpz);

  mpz_clear(mpz);

  det_derr_msg("hex string: %s", hex);

errout:

  return (result);
} // det_data_to_hex

ssize_t
det_hex_to_data(
    void * restrict data,
    size_t data_size,
    const char * restrict hex
    )
{
  ssize_t result = -1;

  if (unlikely(!hex || !data))
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    goto errout;
  }

  if (unlikely(!data_size))
  {
    errno = EINVAL;
    det_derr_ret("Invalid size");
    goto errout;
  }

  if (unlikely((strlen(hex) / 2) > data_size))
  {
    errno = EINVAL;
    det_derr_ret("hex_size not large enough");
    goto errout;
  }

  mpz_t mpz;
  mpz_init(mpz);

  if (gmp_sscanf(hex, "%Zx", mpz) != 1)
  {
    det_derr_msg("Could not read all hex characters");
    goto errout;
  }

  size_t count = 0;

  mpz_export(data, &count, 1, sizeof(uint8_t), 1, 0, mpz);

  mpz_clear(mpz);

  result = (ssize_t) count;

errout:

  return (result);
} // det_hex_to_data
