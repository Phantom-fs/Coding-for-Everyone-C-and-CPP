/*
Program on Array with menu, repeating, different functions etc
*/ 
//Coder: Phantom-fs


#include <stdio.h>
#include <unistd.h>

void lowercase(char *s);

int main()
{
    int arr [1000] = {0};
    int i, j, pos = 0, num = 0;
    int SIZE;
    char input, print, confirm;

    printf("\n************************************************************\n");

    printf("\nEnter the SIZE of the array : ");
    scanf("%d", &SIZE);

    printf("\nEnter the elements of the array : \n\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    sleep(1);

    TOP:     //This is the label for goto statement

    printf("\n************************************************************\n");

    printf("\nPlease enter a valid input from the following Menu : \n");

    printf("\n-------------------------------------------------------------");
    printf("\n| (a) Display of Array elements with suitable headings      |");
    printf("\n-------------------------------------------------------------");
    printf("\n| (b) Insert an element at a given valid position (POS)     |");
    printf("\n-------------------------------------------------------------");
    printf("\n| (d) Delete an element at a given valid position (POS)     |");
    printf("\n-------------------------------------------------------------");
    printf("\n| (c) Calculations on the Array                             |");
    printf("\n-------------------------------------------------------------");
    printf("\n| (s) Sort the Array                                        |");
    printf("\n-------------------------------------------------------------");
    printf("\n| (e) Exit                                                  |");
    printf("\n-------------------------------------------------------------\n");

    printf("\nYour Input : ");
    scanf(" %c", &input);
    lowercase(&input); 

    printf("\n************************************************************\n");

    while(input != 'e')
   {
        switch(input)
        {
            case 'a' :
                printf("\nDisplay of Array elements with suitable headings : \n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("\nElement %d : %d", i + 1, arr[i]);
                }
                break;

            case 'b' :
             B :   //This is the label for goto statement
                printf("\nEnter the position at which you want to insert the element : ");
                scanf("%d", &pos);
                pos -= 1;        //Since the array starts from 0

                if (pos > SIZE)
                {
                    printf("\nInvalid position. Please enter a valid position.\n");
                    goto B;
                }

                printf("\nEnter the element you want to insert : ");
                scanf("%d", &num);

                if (pos > SIZE)
                   goto B;

                else
                {
                    for (i = SIZE+1; i > pos; i--)
                    {
                        arr[i] = arr[i-1];
                    }
                    arr[pos] = num;
                    SIZE++;
                }
                {
                    printf("\nDo you wish to print the array? (y/n) : ");
                    scanf(" %c", &print);
                }      
                break;

            case 'd' :
             D :   //This is the label for goto statement
                printf("\nEnter the position at which you want to delete the element : ");
                scanf("%d", &pos);
                pos -= 1;        //Since the array starts from 0

                if (pos > SIZE)
                {
                    printf("\nInvalid position. Please enter a valid position.\n");
                    goto D;
                }

                printf("\nElement %d at postion %d will be deleted! Confirm? (y/n) : ", arr[pos], pos+1);
                scanf(" %c", &confirm);
                lowercase(&confirm);

                if (confirm == 'y')
                {
                    if (pos > SIZE)
                    {
                        printf("\nInvalid position. Please enter a valid position.\n");
                        goto D;
                    }

                    else
                    {
                        for (i = pos; i < SIZE; i++)
                        {
                            arr[i] = arr[i+1];
                        }
                        SIZE--;
                    }
                }
                else
                {
                    printf("\nElement %d at postion %d will not be deleted! \n", arr[pos], pos+1);
                }
                {
                    printf("\nDo you wish to print the array? (y/n) : ");
                    scanf(" %c", &print);
                }
                break;

            case 'c' :

                printf("\nCalculations on the Array : \n");

                //Sum of all elements
                int sum = 0;
                for (i = 0; i < SIZE; i++)
                {
                    sum += arr[i];
                }

                //Multiplication of all elements    
                long long int mul = 1;
                for (i = 0; i < SIZE; i++)
                {
                    mul *= arr[i];
                }

                //Average of all elements
                double avg = 0;
                for (i = 0; i < SIZE; i++)
                {
                    avg += arr[i];
                }
                avg = avg / SIZE;

                //Maximum element
                int max = arr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] > max)
                    {
                        max = arr[i];
                    }
                }

                //Minimum element
                int min = arr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] < min)
                    {
                        min = arr[i];
                    }
                }

                //Second Maximum element
                int max2 = arr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] > max2 && arr[i] < max)
                    {
                        max2 = arr[i];
                    }
                }

                //Second Minimum element
                int min2 = arr[0];
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] < min2 && arr[i] > min)
                    {
                        min2 = arr[i];
                    }
                }

                //Number of even elements
                int even = 0;
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] % 2 == 0)
                    {
                        even++;
                    }
                }

                //Number of odd elements
                int odd = 0;
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] % 2 != 0)
                    {
                        odd++;
                    }
                }

                //Number of prime elements
                int prime = 0;
                for (i = 0; i < SIZE; i++)
                {
                    int flag = 0;
                    for (j = 2; j <= arr[i] / 2; j++)
                    {
                        if (arr[i] % j == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                    {
                        prime++;
                    }
                }

                //Number of non-prime elements
                int nonprime = 0;
                for (i = 0; i < SIZE; i++)
                {
                    int flag = 0;
                    for (j = 2; j <= arr[i] / 2; j++)
                    {
                        if (arr[i] % j == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                    {
                        nonprime++;
                    }
                }

                //Number of positive elements
                int posi = 0;
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] > 0)
                    {
                        posi++;
                    }
                }

                //Number of negative elements
                int nega = 0;
                for (i = 0; i < SIZE; i++)
                {
                    if (arr[i] < 0)
                    {
                        nega++;
                    }
                }

                printf("\n************************************************************\n");

                printf("\n--------------------------------------------------");  
                printf("\n| Sum of all elements : %d                     ", sum);
                printf("\n--------------------------------------------------");
                printf("\n| Multiplication of all elements : %lld          ", mul);
                printf("\n--------------------------------------------------");
                printf("\n| Average of the array : %.4lf                 ", avg);
                printf("\n--------------------------------------------------");
                printf("\n| Maximum of the Array : %d                    ", max);
                printf("\n--------------------------------------------------");
                printf("\n| Minimum of the Array : %d                    ", min);
                printf("\n--------------------------------------------------");
                printf("\n| 2nd Maximum of the Array : %d                ", max2);
                printf("\n--------------------------------------------------");
                printf("\n| 2nd Minimum of the Array : %d                ", min2);
                printf("\n--------------------------------------------------");
                printf("\n| No. of Even elements in the Array : %d       ", even);
                printf("\n--------------------------------------------------");
                printf("\n| No. of Odd elements in the Array : %d        ", odd);
                printf("\n--------------------------------------------------");
                printf("\n| No. of Prime elements in the Array : %d      ", prime);
                printf("\n--------------------------------------------------");
                printf("\n| No. of non-prime elements in the Array : %d  ", nonprime);
                printf("\n--------------------------------------------------");
                printf("\n| No. of Positive elements in the Array : %d   ", posi);
                printf("\n--------------------------------------------------");
                printf("\n| No. of Negative elements in the Array : %d   ", nega);
                printf("\n--------------------------------------------------\n\n");

                break;

            case 's' :
                printf("\nArray before Sorting : \n\n");
                for (i = 0; i < SIZE; i++)
                {
                    printf("E%d: %d        ",i+1, arr[i]);

                    if((i+1)%5 == 0)      //print new line every 5 elements
                    {
                        printf("\n");
                    }
                }

                printf("\n\nAre you sure you want to sort the array? (y/n) : ");
                scanf(" %c", &confirm);
                lowercase(&confirm);

                if (confirm == 'y')
                {
                    //Bubble Sort
                    for (i = 0; i < SIZE; i++)
                    {
                        for (j = 0; j < SIZE - i - 1; j++)
                        {
                            if (arr[j] > arr[j + 1])
                            {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                    }

                    printf("\nArray after Sorting : \n");
                    for (i = 0; i < SIZE; i++)
                    {
                        printf("E%d: %d        ", i+1, arr[i]);

                        if((i+1)%5 == 0)      //print new line every 5 elements
                        {
                            printf("\n");
                        }
                    }
                }
                else
                {
                    printf("\nArray will not be sorted! \n");
                }
                break;

            default:
                printf("\nInvalid Input. Please try again! \n");
                break;
        }

        lowercase(&print);
        if (print == 'y')
        {
            printf("\n************************************************************\n");

            printf("\nDisplay of Array elements : \n");
            for (i = 0; i < SIZE; i++)
            {
                printf("\nElement %d : %d", i + 1, arr[i]);
            }

            printf("\n\n************************************************************\n\n");
        }

        sleep(4);    //Sleep for 5 seconds before executing further code
        
        printf("\n\n************************************************************\n");

        printf("\nPlease enter a valid input from the following Menu : \n");
        
        printf("\n-------------------------------------------------------------");
        printf("\n| (x) Create a new Array                                    |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (a) Display of Array elements with suitable headings      |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (b) Insert an element at a given valid position (POS)     |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (d) Delete an element at a given valid position (POS)     |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (c) Calculations on the Array                             |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (s) Sort the Array                                        |");
        printf("\n-------------------------------------------------------------");
        printf("\n| (e) Exit                                                  |");
        printf("\n-------------------------------------------------------------");

        printf("\n\nYour Input : ");
        scanf(" %c", &input);
        lowercase(&input);

        printf("\n************************************************************\n");

        if (input == 'x')
        {
            printf("\n\n************************************************************\n");

            printf("\nEnter the SIZE of the array (MAX 1000) : ");
            scanf("%d", &SIZE);

            printf("\nEnter the elements of the array (MAX 1000 elements) : \n\n");
            for (i = 0; i < SIZE; i++)
            {
                printf("Element %d : ", i + 1);
                scanf("%d", &arr[i]);
            }

            goto TOP;     //for reprinting the menu for new array
        }
    }

    printf("\n***********************  THANK YOU  ************************\n");

    printf("\n************************************************************\n");

    return 0;    
}

void lowercase(char *s)
{
    if (*s >= 97 && *s <= 122)
    {
        *s += 0;
    }

    else if (*s >= 65 && *s <= 90)
    {
        *s += 32;
    }
}
