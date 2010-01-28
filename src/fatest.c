#include <common.h>

#include <fa.h>

int
main(int argc, char **argv)
{
  assert(argc == 3);

  // TODO new interface in fa.h; verify correct usage
  struct fa *fa;

  assert(fa_compile(argv[1], strlen(argv[1]), &fa) == REG_NOERROR);

  fa_minimize(fa);

  char *example = NULL;
  size_t size = 0;

  assert(fa_example(fa, &example, &size) == 0);

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
