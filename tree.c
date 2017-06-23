#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"


int check(int N)
{
  if (N < 1)
    return 1;
  if (N >=30)
    return 29;
  return N;
}


int maxH(int tuples[][2],int n, int currentH, int currentL)
{

   if (n < 0)
      return currentH;
   else
   {
      int left_val, right_val = currentH;
      int L = tuples[n][0];
      int H = tuples[n][1];
      //Calculate the new value of H
      int newVal = H + currentH;
      if (currentL >= 0)
         if (currentL - L >=0)
            newVal += L*10;
         else
            newVal += 10*currentL - 20*(L-currentL);
      else
         newVal -= 20*L;

      if (newVal > currentH)
      //try this path
         right_val = maxH(tuples, n-1, newVal, currentL - L);

      //don't eat the n-th food


      left_val = maxH(tuples, n-1, currentH, currentL);

      if (left_val > right_val)
         return left_val;
      else
        return right_val;

   }

}




int main (void)
{
  int L = GetInt();
  int N = check(GetInt());
  int tuples[N][2];
  int i;
  string line;
  //Reading the tuples
  for (i = 0; i < N; i++)
  {
     line = GetString();
     tuples[i][0] = atoi(strtok(line, ", "));
     tuples[i][1] = atoi(strtok(NULL, ", "));
  }

  printf("%d", maxH(tuples, N-1, -10*L, L));

  //freeIt(root);



  return 0;
}
