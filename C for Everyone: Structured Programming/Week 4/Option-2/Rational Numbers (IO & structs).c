/*
Program with with taking input file and converting into the rational (fraction) and perfoming Addtion, Subtraction, Multiplication & Division using structs
*/
//file can be taken both in command line and as a txt file saved in same directory. Both are explained in Comments 
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>

struct rational {
                    int n;          // numerator
                    int d;          // denominator
                } data[1000];

typedef struct rational RATIONAL;

//prototypes
void generate_pairs(FILE *ifp);
void test_pairs(RATIONAL a, RATIONAL b);

//addition
RATIONAL add_rationals(RATIONAL a, RATIONAL b)
{
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = (a.n*b.d) + (b.n*a.d);

    return(r);
}

//subtraction
RATIONAL subtract_rationals(RATIONAL a, RATIONAL b)
{
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = (a.n*b.d) - (b.n*a.d);

    return(r);
}

//multiplication
RATIONAL multiply_rationals(RATIONAL a, RATIONAL b)
{
    RATIONAL r;

    r.d = a.d*b.d;
    r.n = a.n*b.n;

    return(r);
}

//division
RATIONAL divide_rationals(RATIONAL a, RATIONAL b)
{
    RATIONAL r;

    r.d = a.d*b.n;
    r.n = a.n*b.d;

    return(r);
}

int main (int argc, char *argv[])
{
    FILE *ifp;
    char c;

    if(argc != 2)         //the number of arg provided in command line
    {
        printf("\n\nWrong number of arguments, please specify only input file name\n\n");
        exit(1);
    }
  
    ifp = fopen(argv[1], "r");           //take the data i.e. INPUT FILE from the command line   
    
    /*
       We can also take the input or the input file from the local directory (must be in same directory as the program)
       for that, remove if(argc != c) command and 
       change fopen command to ifp = fopen("Text file name.txt", "r"); to take the .txt file
    */

    if (ifp == NULL)
    {
        printf("\n\nFile don't exist!\n\n");
        exit(1);
    }

    //Create pairs
    generate_pairs(ifp);

    //Testing the pairs for operations
    test_pairs(data[0], data[1]);
    
    fclose(ifp);

    printf("\n\n");

    return(0);
}



void generate_pairs(FILE *ifp)
{
    int a[10], *ptr_a, i=0, j=0;

    ptr_a = &a[0];
    

    while(fscanf(ifp, "%d", ptr_a++) == 1) { }    //reading the input file

    printf("\n\nNumber of pairs : %d\n",a[0]);    //creating pairs and storing them in structs
    
    while(++i <= a[0])
    {
        data[j].n = a[(i*2)-1];
        data[j].d = a[i*2];

        printf("\nPair %d: %d/%d\n", j, data[j].n, data[j].d);
        j++;
    }
}

void test_pairs (RATIONAL a, RATIONAL b)
{
    RATIONAL res;      //pair operation result

    //performing the different operations
 
    res = add_rationals(a,b);                           //addition
    printf("Add: %d/%d + %d/%d = %d/%d\n",\ 
            a.n,a.d,b.n,b.d,res.n,res.d);

    res = subtract_rationals(a,b);                      //subtraction
    printf("Subtract: %d/%d - %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);

    res = multiply_rationals(a,b);                      //multiplication
    printf("Multiply: %d/%d * %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);

    res = divide_rationals(a,b);                        //division
    printf("Divide: %d/%d / %d/%d = %d/%d\n",\
            a.n,a.d,b.n,b.d,res.n,res.d);
}










//Inspiration and major code idea form : Shikhar321

//Link : https://github.com/shikhar321/C-for-Everyone-Structured-Programming/blob/main/Week%204/Option%202%20(Natural%20or%20Social%20Science%20Focus).c
