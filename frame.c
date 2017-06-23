#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"
#define MAX 2000


int main (void)
{

  string S = GetString();

  char copy1[MAX];

  strcpy(copy1, S);


  int max = 0;
  string word = strtok(S, " ");

  do
  {
    max = (max >= strlen(word)? max: strlen(word));
  }
  while (word = strtok(NULL, " "));

  //Printing the frame
  int i;
  for (i = 0; i < max+4; i++)
  {
    printf("#");
  }

  puts("");

  word = strtok(copy1, " ");

  do
  {
    printf("# "); printf("%s", word);
    for (i = strlen(word); i < max+1; i++)
      printf(" ");
    printf("#\n");
  }
  while (word = strtok(NULL, " "));
  for (i = 0; i < max+4; i++)
  {
    printf("#");
  }



  return 0;
}
