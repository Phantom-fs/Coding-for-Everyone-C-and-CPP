/*
sine function for an input x between (0, 1) (week 2)
*/
//Coder: Phantom-fs

#include <stdio.h>
#include <math.h>   //maths library have functions like sqrt, sin, cos etc.

int main()
{
  printf("Program to calculate sine function for an input x between (0, 1) in radians\n\n");    //informing what the program is about

    double value = 0.0, result = 0.0;      //declaring in double format

    printf("Enter the number b/w (0,1) (eg. 0.542) : ");
    scanf("%lf",&value);

  //loop statement for condition that value entered must be between (0,1) ****not inclusive*****, for inclusive we can use <= & >=
  if ((value > 0)&&(value < 1)) {

    result = sin(value);      //Calculate the Sine of value

    printf("\nThe Sine of %lf is %lf\n", value, result);      //Display the result of the calculation
  }

  //else the value was entered incorrect
  else {
     printf("Value %lf was not between (0,1), please try again!\n", value);
  }

 return 0;
}
