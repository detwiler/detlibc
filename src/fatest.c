/* $Id$ */

#include <fa.h>

#include <det/common.h>

int
main(int argc, char **argv)
{
  assert(argc == 3);

  fa_t fa;

  assert(fa_compile(argv[1], &fa) == REG_NOERROR);

  fa_minimize(fa);

  char *example = fa_example(fa);

  printf("regexp: %s\n", argv[1]);
  printf("example: %s\n", example);
  
  FILE *file = fopen(argv[2], "w");
  assert(file);

  fa_dot(file, fa);

  free(example);
  fclose(file);
  fa_free(fa);

  return (EXIT_SUCCESS);
} // main()
