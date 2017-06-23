#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"
#define MAX 100
#define MAXX 1000000
int min (int tab[], int n)
{
  int i;
  int min = MAXX;
  for (i = 0; i < n; i++)
  {
    if (min > tab[i] && tab[i] > 0)
      min = tab[i];
  }
  if (min == MAXX)
    min = -1;
  return min;
}

int depth(int matrix[MAX][MAX], int size, int x, int y, int length)
{
   if (length == size)
    return -1;

    int connection[MAX];
    int j = 0;
   if (matrix[x][y] == 1)
    return 1;
   else
   {

     int i;

     for (i = 0; i < size; i++)
     {
       if (matrix[x][i] == 1)
         connection[j++] = depth(matrix, size, i, y, length+1);
     }
     if (min (connection, j) == -1)
        return -1;
      else
        return length+ min(connection, j);
   }


}

int main(void)
{
  int n = GetInt();
  int matrix[MAX][MAX];

  int i, j;
  for (i = 0; i < n; i++)
  {
    j = 0;
    string line = GetString();
    string word = strtok(line, " ");
    do
    {
       matrix[i][j++] = atoi(word);
    }
    while(word = strtok(NULL, " "));
  }

  int x = GetInt();
  int y = GetInt();

  printf("%d", depth(matrix, n, x, y, 1));


  return 0;
}
