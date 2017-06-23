#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"

int indexOfWord(string S, string word  ){

       int i=1,nb=1;
       string w = strtok(S," ");

       if (strcmp(w,word) == 0) return 1;
       i++;
       nb++;
       while((w = strtok(NULL," "))&&(nb<=200))
       {
             if (strcmp(w,word)==0)
                return i;
             i++;  nb++;
      }
      return -1;
}

int main (void)
{
  string S = GetString();
  if (S == NULL)
  { printf("There is no box"); return 0;}
  char cat[] = "cat";
  int i = indexOfWord(S, cat);
  char ordinal[2];

  if (i == -1)
    printf("No cat yet");
  else
  {  switch (i%10)
     {
       case 1:
       {
         if (i/10%10 != 1) // not *11
           {ordinal[0] = 's'; ordinal[1] = 't'; ordinal[2] = '\0';}
         else
           {ordinal[0] = 't'; ordinal[1] = 'h'; ordinal[2] = '\0';}

         break;
       }
       case 2:
       {
         if (i/10%10 != 1) // not *11
           {ordinal[0] = 'n'; ordinal[1] = 'd'; ordinal[2] = '\0';}
         else
           {ordinal[0] = 't'; ordinal[1] = 'h'; ordinal[2] = '\0';}
         break;
       }
       case 3:
       {
         if (i/10%10 != 1) // not *11
           {ordinal[0] = 'r'; ordinal[1] = 'd'; ordinal[2] = '\0';}
         else
           {ordinal[0] = 't'; ordinal[1] = 'h'; ordinal[2] = '\0';}
         break;
       }
       default: ordinal[0] = 't'; ordinal[1] = 'h'; ordinal[2] = '\0';
     }

     printf("The cat is the %d%s item in the box", i, ordinal);


  }

  return 0;

}
