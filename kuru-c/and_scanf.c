#include <stdio.h>

// https://9cguide.appspot.com/15-03.html#S3
int main(void)
{
  char str[256] = "DRAGON";
  scanf("%s", &str[6]); /* 6番の要素のアドレス */
  printf("%s\n", str);
  return 0;
}
