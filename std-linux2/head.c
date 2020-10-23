#include <stdio.h>
#include <stdlib.h>

void do_head(FILE *f, long nlines);

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Useage: %s\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  do_head(stdin, atol(argv[1]));
  exit(EXIT_SUCCESS);
}

void do_head(FILE *f, long nlines)
{
  int c;

  if (nlines <= 0)
    return;

  while ((c = fgetc(f)) != EOF)
  {
    if (putchar(c) < 0)
      exit(EXIT_FAILURE);
    if (c == '\n')
    {
      nlines--;
      if (nlines == 0)
        return;
    }
  }
}
