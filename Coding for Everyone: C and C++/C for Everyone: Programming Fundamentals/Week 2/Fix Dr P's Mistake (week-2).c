/*
Fix Dr. P’s mistake (week 2)
*/
//Program about calculating Sphere's volume

#include<stdio.h>
#define PI 22/7   //or can define PI by 3.14159, once defined it can be assigned any other value

int main()
{
 //declaring in double with initialization
 double radius = 0.0;


 printf("Enter radius:");
 scanf("%lf", &radius);    //scan using lf for double type input

 printf("volume is : %lf \n\n", 4 *PI*radius*radius*radius/3 );    //issue in formula as not using PI as volume of sphere is 4/3*PI*r^3

return 0;
}
