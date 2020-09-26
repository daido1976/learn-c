#include <stdio.h>

// https://9cguide.appspot.com/15-06.html#S3

int getaverage(int data[]);
// 以下でも同じ
// int getaverage(int data[10]);
// int getaverage(int *data);

int main(void)
{
  int average, array[10] = {15, 78, 98, 15, 98, 85, 17, 35, 42, 15};
  printf("array[3] = %d\n", array[3]);
  average = getaverage(array);
  printf("array[3] = %d\n", array[3]);
  printf("%d\n", average);
  return 0;
}

int getaverage(int data[10])
{
  int i, average = 0;
  for (i = 0; i < 10; i++)
  {
    average += data[i];
  }
  data[3] = 111; /* 引数の配列の値を変更 */
  return average / 10;
}
