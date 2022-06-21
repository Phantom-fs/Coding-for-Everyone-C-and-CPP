/*
Program with with taking input file and writing the data to a Binary Tree and printing the data inorder
*/
//file can be taken both in command line and as a txt file saved in same directory. Both are explained in Comments 
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>

typedef int Data;      //int as the data type for the binary tree

typedef struct node {
                       Data d;
                       struct node  *left;
                       struct node *right;
                    } Node;

typedef Node* BTree;      //taking tree as a pointer to node (i.e. pointer to the root therfore th whole tree)

Node *new_node(void)        //single element of node
{
    return malloc(sizeof(Node));
}

//creating new node
Node *init_node(Data d, Node *left, Node *right)
{
    Node *t;
    t = new_node();
    t->d = d;
    t->left = left;
    t->right = right;
    return t;
}

//creating tree, i.e idiom to create the tree
BTree create_tree(Data a[], int i, int SIZE)
{
    if (i>=SIZE)
        return NULL;
    else
        return (init_node (a[i], create_tree(a, i*2+1, SIZE), create_tree(a, i*2+2, SIZE)));
    
}

void in_order(BTree root)     //idiom to print in in-order way
{
    if (root != NULL)
    {
        in_order(root->left);
        printf("%d\t", root->d);
        in_order(root->right);
    }
}

void file_read (FILE *ifp, int SIZE, int d[])        //reading the file input 
{
	int i; 

    for(i = 0; i < SIZE; i++)
    {
        fscanf(ifp, "%d", &d[i]);
    }
}

int main(int argc, char *argv[])
{
    
    FILE *ifp;        //pointer to file
    int SIZE;         //Size of the array

    if(argc != 2)     //no. of arguments on command line
    {
        printf("\n\nWrong number of arguments, please specify only input file name\n\n");
        exit(1);
    }
    
    ifp = fopen(argv[1], "r");    //take the data i.e. INPUT FILE from the command line

    /*
       We can also take the input or the input file from the local directory (must be in same directory as the program)
       for that, remove if(argc != c) command and 
       change fopen command to ifp = fopen("Text file name.txt", "r"); to take the .txt file
    */

    if(fscanf(ifp, "%d", &SIZE) != 1)
    {
        printf("\n\nError! File is empty\n");
        exit(1);
    }
    int data[SIZE];                 //declare the array where SIZE is the no. of elements

    file_read(ifp, data, SIZE);     //we wont rewind the file as we dont require the first elements in INPUT file to be read in

    BTree t;           //declaring the tree

    t = create_tree(data, 0, SIZE);      //creating tree

    in_order(t);       //printing

    fclose(ifp);       //closing the file before exiting
    
    printf("\n\n");

    return 0;
}
