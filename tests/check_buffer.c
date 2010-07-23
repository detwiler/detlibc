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

#include <system.h>

#include <check.h>

#include <det/buffer.h>

Suite*
suite(void);

START_TEST(test_buffer_fread_all)
{
  struct det_buffer *buf = det_buffer_zalloc(0);

  const char *srcdir = getenv("srcdir");

  const char *filename = __FILE__;

  char path[strlen(srcdir) + strlen("/") + strlen(filename)];
  char *mark = path;

  mark = stpcpy(mark, srcdir);
  mark = stpcpy(mark, "/");
  mark = stpcpy(mark, filename);

  FILE *file = fopen(path, "r");

  if (!file)
    det_err_sys("Could not open file: %s", path);

  struct stat sb;

  fstat(fileno(file), &sb);

  ssize_t total = det_buffer_fread_all(buf, file);

  assert(total == sb.st_size);

  fclose(file);

  det_buffer_clear(buf);

  det_buffer_free(buf);
} // test_buffer_fread_all
END_TEST

Suite*
suite(void)
{
  Suite *s = suite_create("det_buffer");

  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_buffer_fread_all);
  suite_add_tcase(s, tc_core);

  return (s);
} // suite

int
main(void)
{
  int failed;
  Suite *s = suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return ((failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
} // main()
