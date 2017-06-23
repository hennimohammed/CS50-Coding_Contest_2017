#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"



int converter (char x)
{
  int result;
  switch (x) {
    case 'M': {result = 1000;break;}
    case 'C': {result = 100;break;}
    case 'D': {result = 500;break;}
    case 'L': {result = 50;break;}
    case 'X': {result = 10;break;}
    case 'V': {result = 5;break;}
    case 'I': {result = 1;break;}
    default:
      result = 0;
  }

  return result;
}

int main (void)
{
  string R = GetString();
  int len = strlen(R);

  int i, result = converter(R[len-1]);


  for (i = len-1; i > 0; i--)
    result += (converter(R[i]) > converter(R[i-1]) ? -1*converter(R[i-1]) : converter(R[i-1]));


  printf("%d", result);
  return 0;


}
