/*
Sine & Cosine table in (0,1) range
*/
//Simple usage of for loop and interval equation to get .x terms
//Coder: Phantom-fs

#include<stdio.h>
#include<math.h> //to use sine and cosine function

int main(void)
{
  double interval, sine_val, cosine_val;    //declaration of variables
  int i;

  printf("Sine & Cosine table in (0,1) range\n");
  
  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

  for(i = 0; i <= 50; i++)
    {
    interval = i/50.0;

    sine_val = sin(interval);    //equation for sine
    printf("sin(%lf) = %lf\t", interval, sine_val);  // table printing for sine function. \t is tab, it leaves 8 spaces, helps to make table like format

    cosine_val = cos(interval);    //equation for cosine
    printf("Cos(%lf) = %lf\n", interval, cosine_val);  // table printing for cosine function
    }

  printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

return 0;
}

/*instead of using i/50, we can also have the input from the user and then divide it by i, to get personalized table like:
  we can get input from user say x (using common scanf method in int from)
   for(i = 0; i < x; i++)
    {
    interval = i/x;
    ......
  now with this the output table will have that each interval with that length
  like if x = 4 then four values of sin and cosine table will be printed i.e. 0.0, 0.25, 0.50 and 0.75 (if we put i<=x then 5 values).
  similarly we can have table based on our preferred interval length
*/  
