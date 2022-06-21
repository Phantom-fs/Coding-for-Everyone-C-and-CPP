/*
Program with with taking input file and writing the data, avg and max to output file and std out
*/
//file can be taken both in command line and as a txt file saved in same directory. Both are explained in Comments 
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void file_read (FILE *ifp, int SIZE, int d[])        //reading the file input 
{
	int i; 

    for(i = 0; i < SIZE; i++)
    {
        fscanf(ifp, "%d", &d[i]);
    }
}

void average (int SIZE, int d[], double *avg1)                       //avg of integers present in the file
{
	double avg;
	int i;

	for(i = 0; i < SIZE; i++)
    {
		avg += d[i];                                 //reading the elements
	}

    printf("\n\nAverage of the integers = %lf", avg/SIZE);

    *avg1 = avg/SIZE;     //to write into the output file, we need a variable
}

void max_number (int SIZE, int d[], int *max1)
{
    if (SIZE < 1)
    {
        printf("No data in the file");
        exit(1);
    }

    int i;
    int MAX = d[0];

    for(i = 1; i < SIZE; i++)
    {
        if(d[i] >  MAX)
            MAX = d[i];
    }
    
    printf("\n\nThe maximum of the number = %d", MAX);

    *max1 = MAX;       //to write into the output file, we need a variable
}

//function to write all these value into the OUTPUT FILE
void write_to_file (FILE *ifp, FILE *ofp, int SIZE, int DATA[], double avg, int max)
{
    int i;

    fprintf (ofp, "\nThe values of the array are : \n");

    for (i=0; i<SIZE; i++)
    {
        fprintf(ofp, "%d\t", DATA[i]);

        if ((i + 1) % 8 == 0)       //new line every 8 elements
          fprintf(ofp, "\n");
    }   

    fprintf (ofp, "\n\navg of value = %.4lf", avg);
    fprintf (ofp, "\n\nmax value = %d", max);
}


int main (int argc, char *argv[])
{
    FILE *ifp, *ofp;      //pointers to our I/O Files
    int i, SIZE, max1 = 0;
    double avg1 = 0;

    if(argc != 2)         //the number of arg provided in command line
    {
        printf("\n\nWrong number of arguments, please specify only input file name\n\n");
        exit(1);
    }
  
    ifp = fopen(argv[1], "r");           //take the data i.e. INPUT FILE from the command line
    ofp = fopen("answer-hw3", "w+");    
    
    /*
       We can also take the input or the input file from the local directory (must be in same directory as the program)
       for that, remove if(argc != c) command and 
       change fopen command to ifp = fopen("Text file name.txt", "r"); to take the .txt file
    */

    fscanf(ifp, "%d", &SIZE);
    int DATA [SIZE];                     //declare the array where SIZE is the no. of elements

    file_read (ifp, SIZE, DATA);         //we wont rewind the file as we dont require the first elements in INPUT file to be read in
    
    printf("\n\nThe elements of the array : \n");
    for (i=0; i < SIZE; i++)
    {
        printf("%d\t", DATA[i]);
    }

    average (SIZE, DATA, &avg1);                //average of int
    max_number (SIZE, DATA, &max1);             //max of integers

    write_to_file (ifp, ofp, SIZE, DATA, avg1, max1);     //write into output file answer-hw3.txt

    printf("\n\n");

    fclose(ifp);
    fclose(ofp);

    return 0;
}
