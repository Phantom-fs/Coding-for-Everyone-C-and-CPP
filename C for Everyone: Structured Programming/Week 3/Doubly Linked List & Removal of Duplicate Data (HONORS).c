/*
Program to create doubly linked list, sorting it and removing duplicate elements from it
*/
//HONORS
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 200      //200 element list

//doubly linked list
typedef struct list{
                        int data;
                        struct list *next;
                        struct list *prev;
                    } list;


int list_empty(const list *li){ return (li == NULL);}     //const as dont want any change to list

// This method initializes a head of a list and returns it
list *create_list (int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    head ->prev = NULL;

    return head;
}

//creating list with dual pointer i.e. doubly linked list
list *add_to_front(int d, list *h)
{
    list *head = create_list(d);       //create element head and link it to existing element h where head (new element) next pointer
    head -> next = h;                  //is h (existing) and h (existing) previous element is head (new)
    h -> prev = head;
    return head;
}

//converting array data to doubly linked list
list *array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);         //first element
    int i;
    for(i = 1; i< size; i++)
    {
        head = add_to_front(d[i], head);    //add d[i] element (new element) to the front of existing element head,
    }                                       //then make this element into new head and so on.
    return head;
}

//Print list
void print_list (list *h, char *title)
{
    printf("%s\n", title);
    int i = 0;

    while(h != NULL)
    {
        // If we are at the last element in the list no need for '\t'
        if(i != SIZE-1)
            printf("%d\t", h->data);
        else
            printf("%d", h->data);

        // Break line every 8 elements
        if ((i + 1) % 8 == 0)
        {
            printf("\n");
        }
        // Move h to the next node
        h = h -> next;
        i++;
    }
    printf("\n\n");
}

//Swaps the data of two given pointers to different nodes in a doubly linked list
void swap_nodes(list *p1, list *p2)
{
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
    return;
}

//Bubble sort the doubly linked list
void sort_list(list *h){
    int i, j;
    list *p1, *p2;

    //as the list is not a array, with swap only 1 element is swapped or exchanged, while in array
    //its data[j+1] > data[j], thus upon iteration the element changes. Here in the List to change
    //the element, we change the p1 element to the current p2 element and change p2 element to the
    //element coming after p2 (p2 -> next). Similarly after a complete j iterative loop, we go back
    //i iterative loop, where we reassign p1 to the head of list and p2 to the next element

    for(i = SIZE-2; i >= 0; i--)
    {
        p1 = h;
        p2 = p1->next;

        for(j = 0; j <= i; j++)
        {
            if(p1->data > p2->data)
                swap_nodes(p1, p2);
            p1 = p2;
            p2 = p2->next;
        }
    }

}

//Remove an element from list
void remove_element(list *node)
{
    if(node != NULL)
    {
        //single element list
        if (node->prev == NULL && node->next == NULL)     //both th next and prev pointers point to NULL
        {
            node = NULL;
            return;
        }

        //Element is head
        else if(node->prev == NULL)
        {
            list *my_next = node->next;      //assign new head
            node->next = NULL;
            my_next->prev = NULL;            //new head prev pointer set to NULL as the head dont have prev pointers
            return;
        }

        //Last element
        else if (node->next == NULL)
        {
            list *my_prev = node->prev;      
            node->prev = NULL;
            my_prev->next = NULL;           //new last next pointer set to null as the pointer of last element is tail (i.e. NULL)
            return;
        }
        
        //normal in b/w element
        else
        {
            list *my_prev = node->prev;
            list *my_next = node->next;

            node -> next = NULL;           //removing element from list
            node -> prev = NULL;

            my_prev -> next = my_next;
            my_next -> prev = my_prev;

            return;
        }

    }
}

//Remove duplicate from the list
void remove_dups(list *h)
{
    while (h->next != NULL)
    {
        if (h->data == h->next->data)    //element same
        {
            remove_element(h->next);
        }

        else
            h = h->next;                 //go ahead in list if pointers are diff
    }
}

//function to count the number of elements in the list
void count_elements(list *h, char* cond)
{
    int count;

    while (h == NULL)
    {
        count++;
        h = h ->next;
    }
    
    printf("\nNumber of elements %s from the list = %d", cond, count);
}

int main()
{
    int i;
    list *list1 = create_list (rand()%49);   //first element of list

    for(i = 0; i < SIZE-1; i++)
    {
        list1 = add_to_front(rand()%49, list1);       //creating a random generated list
    }

    print_list(list1, "\n\nList before sorting : \n");

    sort_list(list1);
    print_list(list1, "\n\nList after Sorting : \n");
    count_elements(list1, "before the removal of duplicates");

    remove_dups(list1);
    print_list(list1, "\n\nList after duplicate removal : \n");
    count_elements(list1, "after the removal of duplicates");

    printf("\n\n");

    return 0;
}
