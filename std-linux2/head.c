#include <stdio.h>
#include <stdlib.h>

void do_head(FILE *f, long nlines);

int main(int argc, char const *argv[])
{
  long nlines;

  if (argc < 2)
  {
    fprintf(stderr, "Useage: %s n [file file...] \n", argv[0]);
    exit(EXIT_FAILURE);
  }

  nlines = atol(argv[1]);
  if (argc == 2)
  {
    do_head(stdin, nlines);
  }
  else
  {
    int i;
    for (i = 2; i < argc; i++)
    {
      FILE *f;

      f = fopen(argv[i], "r");
      if (!f) // Equivalent to `if(f == NULL)`
      {
        perror(argv[i]);
        exit(EXIT_FAILURE);
      }
      do_head(f, nlines);
      fclose(f);
    }
  }
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
