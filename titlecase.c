#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"

#define MAX 100
int isNotConjunction(string word)
{

    string tab[]= {"the", "and", "of", "but"};

    if (! (strncmp(tab[0], word, 3) && strncmp(tab[1], word, 3) && strncmp(tab[3], word, 3)))
      if (!isalpha(word[3]))
        return 0;
    if (!strncmp(tab[2], word, 2))
      if (!isalpha(word[2]))
        return 0;

    return 1;
}

void capitalizeLastWord(char * s)
{
  int i;
  for (i = strlen(s) - 1; i > 0; i--)
  {
    if (s[i-1] == ' ')
    {
      s[i] = toupper(s[i]);
      break;
    }
  }
  return ;
}
void capitalize(char * word)
{
  word[0] = toupper(word[0]);
  return;
}
int main(void)
{
  char sep[]= " ";

  string S = GetString();

  char result[MAX];
  result[0] = '\0';

  string word = strtok(S, sep);
  //Capitalize first word
  capitalize(word);
  strncat(result, word, strlen(word));

  while(word = strtok(NULL, sep))
  {

    if (isNotConjunction(word))
      capitalize(word);
    strncat(result, " ", 1);
    strncat(result, word, strlen(word));
  }

  strcat(result, "\0");
  capitalizeLastWord(result);

  printf("%s", result);
  return 0;

}
