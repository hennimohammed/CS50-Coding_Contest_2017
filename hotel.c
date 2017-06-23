#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"

#define MAXN 100
#define MAXM 200

int main (void)
{
  int N, M;
  string number = GetString();
  strtok(number, " ");
  string test = strtok(NULL, " ");
  M = atoi(test);
  N = atoi(number);

  int matrix[MAXN][MAXM];
  int i,j;

  for (i = 0; i < N; i++)
  {
    string line = GetString();
    for (j= 0; j< M; j++)
      matrix[i][j] = (line[j] == '0'? 0: 1);

  }

  int S = GetInt();

  int cpt = 0;

  for (i = 0; i < N; i++)
  {

    for (j= 0; j< M; j++)
    {
      if (matrix[i][j] == 0)
        cpt++;
      else
        cpt = 0;

      if (cpt == S)
        break;

    }
    if (cpt == S)
      break;
  }


  printf("%d" , (cpt == S));
  return 0;


}
