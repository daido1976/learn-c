#include <stdio.h>

// https://9cguide.appspot.com/15-06.html#S2

int getaverage(int data[10]);

int main(void)
{
  int average, array[10] = {15, 78, 98, 15, 98, 85, 17, 35, 42, 15};
  average = getaverage(array);
  printf("%d\n", average);
  return 0;
}

int getaverage(int data[10])
{
  int i, sum = 0;
  for (i = 0; i < 10; i++)
  {
    sum += data[i];
  }
  return sum / 10;
}
