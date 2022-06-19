/*
Program to create a int list with random input and bubble sort the contents
*/
//Option-1 (General)
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>        //needed for seed() for srand() for use of random number creation 

#define SIZE 100         //list of 100 integer elements

typedef struct list{ 
                        int data;
                        struct list *next;
                   } list;

int is_empty(const list *list1){ return (list1 == NULL);}

//create a single element list
list *create_list (int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

//create a element and add it to the previous element in the list
list *add_to_front (int d, list *h)
{
    list *head = create_list(d);
    head -> next = h;
    return head;
}

//convert the data stored in array into the list
list *array_to_list (int d[], int size)
{
    int i;
    list *head = create_list(d[0]);    //first element

    for(i = 1; i< size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title)
{
    printf("%s\n", title);
    int i = 0;

    while(h != NULL)
    {
        if(i != SIZE-1)
            printf("%d\t", h->data);
        else
            printf("%d", h->data);

        //new line every 8 elements
        if ((i+1) % 8 == 0)
        {
            printf("\n");
        }

        h = h -> next;

        i++;
    }

  printf("\n");
}

void swap(list *p1, list *p2)
{
    int temp = p1->data;    //store data of the pointer1 in temp file
    p1->data = p2->data;    //swap the data of p1 with p2
    p2->data = temp;        //put p1 data from temp to p2
}

//bubble sort to sort the list
void sort_list(list *h)
{
    int i, j;
    list *p1, *p2;

    for(i = SIZE-2; i >= 0; i--)
    {
        p1 = h;
        p2 = p1->next;

        for (j = 0; j <= i; j++)
        {
            if(p1->data > p2->data)      //as the list is not a array, with swap only 1 element is swapped or exchanged, while in array
                swap(p1, p2);            //its data[j+1] > data[j], thus upon iteration the element changes. Here in the List to change
                                         //the element, we change the p1 element to the current p2 element and change p2 element to the
            p1 = p2;                     //element coming after p2 (p2 -> next). Similarly after a complete j iterative loop, we go back
            p2 = p2->next;               //i iterative loop, where we reassign p1 to the head of list and p2 to the next element
        }
    }

}


int main ()
{
    int i;
    srand(time(0));                            //seed the rand() and seed is set to system time

    list *L = create_list(rand() % 100);       //first element
    
    for(i = 1; i < SIZE; i++)
    {
        L = add_to_front (rand() % 1000, L);    //taking a random number and adding it to the list
    }
    print_list(L, "\n\nList Before sorting : \n");

    sort_list(L);

    print_list(L, "\n\nList After Sorting : \n");

    return 0;    
}
