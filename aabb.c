#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cs50.h"
#include<math.h>

double min(double a, double b)
{
  if (a < b)
    return a;
  else
    return b;

}
double max(double a, double b)
{
  if (a >= b)
    return a;
  else
    return b;

}
double Abs(double x)
{
  x = floorf(x * 10) / 10;
  if (x < 0)
    return 0.0;
  else if (x > 10000.0)
      return 10000.0;
  else
    return x;
}
double normalize(double x)
{
  x = floorf(x * 10) / 10;
  if (x > 1000000.0)
    return 1000000.0;
  else if (x < -1000000.0)
    return -1000000.0;
  else return x;
}

int main(void)
{
   string line = GetString();

   string word = strtok(line, " ");
   double x1 = normalize(atof(word));

   word = strtok(NULL, " ");
   double y1 = normalize(atof(word));
   word = strtok(NULL, " ");
   double w1 = normalize(Abs(atof(word)));
   word = strtok(NULL, " ");
   double h1 = normalize(Abs(atof(word)));

   line = GetString();
   word = strtok(line, " ");
   double x2 = normalize(atof(word));
   word = strtok(NULL, " ");
   double y2 = normalize(atof(word));
   word = strtok(NULL, " ");
   double w2 = normalize(Abs(atof(word)));
   word = strtok(NULL, " ");
   double h2 = normalize(Abs(atof(word)));

   double horizontal11, horizontal21;
   double vertical11, vertical21;

   horizontal11 = x1; horizontal21 = x1 + w1;
   vertical11 = y1; vertical21 = y1 + h1;




   double horizontal12, horizontal22;
   double vertical12, vertical22;

   horizontal12 = x2; horizontal22 = x2 + w2;
   vertical12 = y2 ; vertical22 = y2 + h2;

   double result = (max(horizontal12, horizontal11) - min(horizontal22, horizontal21))*(max(vertical11, vertical12)- min (vertical21, vertical22));

   if (result > 0)
    printf("%.2f", result);
   else
      printf("%.2f", 0.00);




   return 0;

}
