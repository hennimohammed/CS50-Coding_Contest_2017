#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"


int abs(int x)
{
  return (x >= 0? x: 0);
}

int main (void)
{

  int F = abs(GetInt()%INT_MAX);
  int D = abs(GetInt()%INT_MAX);



  int i, j = -1;
  for (i = 0; i < D; i++)
  {
    F -= abs(GetInt()%INT_MAX);

    if (F <= 0 && j == -1)
      j = i;
  }

  if (F > 0)
    printf("Happy Cat!");
  else
    printf("%d", j);
  return 0;
}
