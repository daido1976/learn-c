#include <stdio.h>

// https://9cguide.appspot.com/15-05.html#S2
int main(void)
{
  int *p = NULL;
  int i;
  p = &i;
  printf("p = %p\n", p);
  printf("&i = %p\n", &i);
  return 0;
}
