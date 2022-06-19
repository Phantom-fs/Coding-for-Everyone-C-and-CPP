/*
Program to create elements with their Name, Symbol and atomic wt. and store it in list
*/
//Option-2 (Natural or Social Science Focus)
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>

//element ADT
typedef struct element {
                           char name[30];
                           char symbol[10];
                           double weight; 
                       } element;

//List ADT
typedef struct list {
                        element ele;
                        struct list *next;
                    } list;

//create a single element list
list* create_list(element e)
{
    list* head = malloc(sizeof(list));
    head-> ele = e;
    head-> next = NULL;
    return head;
}

//add element to the list
list* add_to_front(element e, list* h)
{
    list* head = create_list(e);
    head->next = h;
    return head;
}

//Convert data from array to list
list* array_to_list(element e[], int size)
{
    list* head = create_list(e[0]);
    int i;

    for (i=1; i<size; i++)
    {
        head = add_to_front(e[i], head);
    }
    return head;
}

//Prints the info from the element struct
void print_element(element* e)
{
    printf("\nElement %s\n\tsymbol : %s\n\tatomic weight : %.4lf\n", e->name, e->symbol, e->weight);
}

//Prints the list elements
void print_list(list *h, char *title)
{
    printf("%s\n", title);
    while (h != NULL)
    {
        print_element(&h-> ele);
        h = h->next;
    }
}

int main()
{
    list* head = NULL;
    
    //creating elements
    element e1 = {"Neon", "Ne", 20.180};               
    element e2 = {"Fluorine", "F", 	18.998};
    element e3 = {"Oxygen", "O", 15.999};
    element e4 = {"Nitrogen", "N", 14.007};
    element e5 = {"Carbon", "C", 12.011};
    element e6 = {"Boron", "B", 10.811};
    element e7 = {"Beryllium", "Be", 9.012};
    element e8 = {"Lithium", "Li", 6.941};
    element e9 = {"Helium", "He", 4.003};
    element e10 = {"Hydrogen", "H", 1.008};
    
    element e_array[10] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10};    //storing elements data into an array for easy access

    head = array_to_list(e_array, 10);
    
    print_list(head, "\n\nElements list : \n");

    printf("\n\n");
    
    return 0;
}
