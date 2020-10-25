#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#define DEFAULT_N_LINES 10

void do_head(FILE *f, long nlines);

static struct option longopts[] = {
    {"lines", required_argument, NULL, 'n'},
    {"help", no_argument, NULL, 'h'},
    {0, 0, 0, 0}};

int main(int argc, char *argv[])
{
  int opt;
  long nlines = DEFAULT_N_LINES;

  while ((opt = getopt_long(argc, argv, "n:h", longopts, NULL)) != -1)
  {
    switch (opt)
    {
    case 'n':
      nlines = atol(optarg);
      break;
    case 'h':
      fprintf(stdout, "Useage: %s [-n lines] [FILE ...]\n", argv[0]);
      exit(EXIT_SUCCESS);
    case '?':
      fprintf(stderr, "Useage: %s [-n lines] [FILE ...]\n", argv[0]);
      exit(EXIT_FAILURE);
    default:
      break;
    }
  }

  if (optind == argc)
  {
    do_head(stdin, nlines);
  }
  else
  {
    int i;
    for (i = optind; i < argc; i++)
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
