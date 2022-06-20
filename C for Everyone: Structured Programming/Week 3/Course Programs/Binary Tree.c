#include <stdio.h>
#include <stdlib.h>

//Integer data type binary tree
typedef int Data;

//Defining a node
typedef struct node{
    Data d;
    struct node  *left;
    struct node *right;
}Node;

typedef Node* BTree;

void in_order(BTree root){
    if(root == NULL)
        return;
    else{
        in_order(root->left);
        printf("%d\n", root->d);
        in_order(root->right);
    }
}

Node *new_node(void){
    return malloc(sizeof(Node));
}

Node *init_node(Data d, Node *left, Node *right){
    Node *t;
    t = new_node();
    t->d = d;
    t->left = left;
    t->right = right;
    return t;
}

BTree create_tree(Data a[], int i, int size){
    if (i>=size)
        return NULL;
    else
        return init_node(a[i], create_tree(a, i*2+1, size), create_tree(a, i*2+2, size));
    
}

int main(void){
    int d[] = {0,1,2,3,4,5,6};
    BTree bt;
    bt = create_tree(d, 0, 7);
    in_order(bt);
    return 0;
}

