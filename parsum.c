#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"




int main (void)
{
    string str = GetString();

    int result = 0;
    int len = strlen(str);
    char op = ' ';
    int n = 0;
    int i;

    for (i = 0; i < len; i++)
    {
      switch (str[i])
      {
        case '-':
        {
          if (op == '-')
              result -= n;
          else
              result += n;
          n = 0;
          op = '-';

          break;
        }
        case '+':
        {
          if (op == '-')
              result -= n;
          else
              result += n;
          op = '+';
          n = 0;
            //printf("\nresult = %d n = %d\n", result, n);
          break;
        }
        case ' ':{  break;}

        default:
        {//The caracter is a numerical
            char num[8];
            num[0] = str[i];
            num[1] = '\n';
            n = (n*10 + atoi(num))%10000000;

            break;
        }
      }
    }
    //The last number
    if (op == '-')
        result -= n;
    else
        result += n;

    printf("%d\n", result);


  return 0;
}
