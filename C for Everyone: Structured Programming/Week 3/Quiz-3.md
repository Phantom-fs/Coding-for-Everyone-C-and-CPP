QUIZ-3 Answers with Reasoning

********************************************************************************************************************************************

Q1. The C library function malloc()

ANS. returns a pointer

*//malloc() allocates requested memory and returns a pointer to it, i.e. it return the address to the memory we took off from the heap.*

********************************************************************************************************************************************

Q2. The code

    while(h != NULL) {
    …
    }
    
   Is typical for:
   
ANS. Processing a list

*//The loop will iterate through the list until it hits a NULL value, therefore looping over every valuable element in the list.*

********************************************************************************************************************************************

Q3. The code
    
    void concat(list* h1, list* h2)
    
   as described concatenates two lists. If list h1 has n elements and list h2 has m elements where m > n,  then concatenation 
   takes approximately proportional to list lengths
   
ANS. n

*//have to find the end of the first list then simply tie it to head of second list using the tail pointer of h1 list (with n elements)*

********************************************************************************************************************************************

Q4. A complete binary tree of depth 5 would have

ANS. 32 leaf nodes

*//2^5 = 32. Have a factor of 2*

********************************************************************************************************************************************

Q5. The code

    void postorder(BTREE root)
    {
        if (root != NULL)
        {
           postorder(root -> left);
           postorder(root -> right);
           printf(“%c “, root -> d);
        }
    }
    
ANS. Is recursive

*//postorder() calls itself in its own function*

********************************************************************************************************************************************
   
Q6. The C library function calloc()

ANS. sets memory to 0

*//calloc() allocates requested memory, returns a pointer to it, and sets it to 0*

********************************************************************************************************************************************

Q7. The code

    while(h != NULL) {
    …
    }
    
   is not ideal when:

ANS. h can never equal to NULL

*//the loop will become infinite in this case and won't be able to break out from the loop*

********************************************************************************************************************************************

Q8. The code

    void concat(list* h1, list* h2)
    
   as described concatenates two lists. If list h1 has n elements and list h2 has m elements where m < n,  then concatenation
   takes approximately proportional to list lengths
    
ANS. n

*//have to find the end of the first list – but then simply tie it to head of second list. As explained in Q3*

********************************************************************************************************************************************

Q9. A complete binary tree of depth 8 would have

ANS. 256

*//2^8 = 256*

********************************************************************************************************************************************

Q10. The code

    void postorder(BTREE root)
    {
        if (root != NULL)
        {
           postorder(root -> left);
           postorder(root -> right);
           printf(“%c “, root -> d);
        }
    }
    
ANS. Will make no change to a given BTREE object

*//postorder() simply prints the root value of a given BTREE after calling itself on the left and right branches of the root.*

********************************************************************************************************************************************
