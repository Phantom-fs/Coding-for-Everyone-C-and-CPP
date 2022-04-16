#include <stdio.h>
#include <stdlib.h>

int main(){
    int SIZE;                 //custom size, no of elements we wan to enter
    int numberarray[1000];    //declaring the array
    int i;
    unsigned int sum = 0;     //as sum will be very large
    double avg;               //average will be in double format

    printf("\n\nProgram to read data into array and calculate average :");

    printf("\n\nEnter the numbers of weights you wish to enter (between 0 and 1000) : ");
    scanf(" %d", &SIZE);

    printf("\n\n");

    for(i = 0; i < SIZE; ++i) {         //loop for entering the elements of the array
    printf("Enter number %d: ",i+1);
    scanf("%d", &numberarray[i]);
          
    sum += numberarray[i];              //adding the elements of the array
    }

    avg = sum/(SIZE + 0.0);  //sum divide by total no of observation SIZE, here adding 0.0 so that no conversion happens
                             //as sum is in int type and SIZE is also in int type

    printf("\n\nSum of set of elephant seals is %u", sum);

    printf("\n\nAverage weight for the set of the elephant seals = %lf\n\n", avg);

    return 0;
}
