/*
Average weight of Elephant Seals read into an array
*/
//Taking the average using the data.txt file provided. reading all that data into an array and calc avg
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *data;    //pointer to our file
    data = fopen("elephant_seal_data.txt", "r");   //elephant_seal_data.txt must be in the same directory as the program

    const int SIZE = 1000;    //size of array is 1000 as there are 1000 numbers given (4 digit) in data file
    int numberarray[SIZE];    //declaring the array
    int i;
    unsigned int sum = 0;   //as sum will be very large
    double avg;                  //average will be in double format

    printf("\n\nProgram to read data into array and calculate average :");

    if (data == NULL){
        printf("Error Reading File\n");          //termination or EOF
        exit (0);
    }

    for (i = 0; i < SIZE; i++){
        fscanf(data, "%d,", &numberarray[i] );   //reading each number into the array using fscanf
    }

    for (i = 0; i < SIZE; i++){                  //adding each element of the array
        sum = sum + numberarray[i];
    }

    avg = sum/1000.0;  //sum divide by total no of observation i.e 1000, here using 1000.0 instead of SIZE so that no conversion happens
                       //as sum is in int type and SIZE is also in int type

    printf("\n\nSum of set of elephant seals is %u", sum);

    printf("\n\nAverage weight for the set of the elephant seals = %lf\n\n", avg);

    fclose(data);     //closing the file

    return 0;
}

//ANS :-
//sum is 6840015
//average is 6840.015
