/*
Program with custom Month and Date data type created using enum and struct
*/
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>

typedef enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;

typedef struct full_date{
                            month m;
                            int d;
                        } date;
int max_days;

void printday(date *ptr_date)              //ptr_date is pointer to date strut
{
    switch(ptr_date-> m)
    {
        case JAN:
            printf("January %d", ptr_date->d);
            max_days = 31; break;

        case FEB:
            printf("February %d", ptr_date->d);
            max_days = 28; break;

        case MAR:
            printf("March %d", ptr_date->d);
            max_days = 31; break;

        case APR:
            printf("April %d", ptr_date->d);
            max_days = 30; break;

        case MAY:
            printf("May %d", ptr_date->d);
            max_days = 31; break;

        case JUN:
            printf("June %d", ptr_date->d);
            max_days = 30; break;

        case JUL:
            printf("July %d", ptr_date->d);
            max_days = 31; break;

        case AUG:
            printf("August %d", ptr_date->d);
            max_days = 31; break;

        case SEP:
            printf("September %d", ptr_date->d);
            max_days = 30; break;

        case OCT:
            printf("October %d", ptr_date->d);
            max_days = 31; break;

        case NOV:
            printf("November %d", ptr_date->d);
            max_days = 30; break;

        case DEC:
            printf("December %d", ptr_date->d);
            max_days = 31; break;
    }
}

date *nextday(date *dt)
{
    if (dt->d == max_days)                 //last day of the month
    {
        dt->d = (dt->d + 1) % max_days;
        dt->m = (dt->m + 1) % 12;          //%12 when last day of year
    }

    else                                   //If not the end of month, then increment to next day
        dt->d = (dt->d + 1);

  return dt;
}

int main()
{
    int i;

    date date_1 = {JAN, 1};
    date date_2 = {FEB, 28};
    date date_3 = {MAR, 14};
    date date_4 = {OCT, 31};
    date date_5 = {DEC, 31};
    date date[] = {date_1, date_2, date_3, date_4, date_5};     //putting each date in array, to print later
    
    for (i=0; i<5; i++)
    {
        printf("\n\nDate is ");
        printday(&date[i]);

        printf("\nNext day is ");
        nextday(&date[i]);              //changing the value using the function (call by value)
        printday(&date[i]);
    }

    printf("\n\n");

    return 0;
}
