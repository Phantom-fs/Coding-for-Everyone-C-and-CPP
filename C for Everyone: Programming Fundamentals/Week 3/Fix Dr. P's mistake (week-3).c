/*
Fix Dr. P's mistake (week-3)
*/
//Mistake was using abs()
//Coder: Phantom-fs

#include<stdio.h>
#include<math.h> //has sin(), abs(), fabs(), sqrt() etc

int main(void)
{
  double interval;
  int i;
  for(i = 0; i <30; i++)
    {
    interval = i/10.0;
    printf("sin( %lf ) = %f \t \n", interval,fabs(sin(interval)));  //correction is using fabs() function
    }

  printf("\n+++++++++++++++\n");

 return 0;
}
