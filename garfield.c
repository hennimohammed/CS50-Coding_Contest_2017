#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"cs50.h"

int check(int N)
{
  if (N < 1)
    return 1;
  if (N >=30)
    return 29;
  return N;
}

void decimalToBinary(int num, int n, char result[])
{
   int i = n-1;
   while (num > 0)
   {
     result[i--] = (num%2 == 0? '0': '1') ;
     num = num/2;
   }
   for (i = i; i >=0; i--)
   {
     result[i] = '0';
   }
   return ;
}

long double power(int n, int m)
{
  int i;
  long double result = 1;
  for (i = 0; i < m; i++)
  {
    result *= n;
  }

  return result;
}

int main (void)
{

   int L = GetInt();
   int N = check(GetInt());
   int tuples[N][3];
   int i;
   string line;
   //Reading the tuples
   for (i = 0; i < N; i++)
   {
      line = GetString();
      tuples[i][0] = atoi(strtok(line, ", "));
      tuples[i][1] = atoi(strtok(NULL, ", "));
   }

   //Trying all possibilities
   int j;
   long double possibilities = power(2, N);
   char binary[N];
   int previousH;

   int saveL, H,cancel, HMax = -10*L;
   saveL = L;
   for (i = 1; i < possibilities; i++)
   {
      H = 0;
      previousH = 0;
      L = saveL;
      cancel = 0;


      decimalToBinary(i, N, binary);

      for (j = 0; j < N; j++)
      {
        if (tuples[j][1] <= 0)
        {
          cancel = 1;
          break;
        }
        if (binary[j] == '1')//Take this food
        {

          if ((L - tuples[j][0] <= 0) && (previousH > (H + tuples[j][1] - 20*(L-tuples[j][0]))))
          {
            cancel = 1;
            break;
          }

           H += tuples[j][1]; //increase happiness
           L -= tuples[j][0];  //decrease hunger

           if (H <= 0)
            {  cancel=  1; break; }


           previousH = H;
        }
      }
      if (!cancel)
      {
        if (L > 0)
            H -= L*10; //10 for each hunger unit
        else if (L <0)
            H += L*20; //20 for each overfeeding unit

        if (H > HMax)
          HMax = H;
      }
   }

   printf("%d", HMax);

   return 0;
}
