QUIZ-2 Answers with Reasoning

********************************************************************************************************************************************

Q1. In the struct

    struct point{
    double x;
    double y;
    } p1 = { 2.5, 4.0};
   
   The value of p1.x is
  
ANS. 2.5

//*x is assigned to 2.5 and y to 4.0

********************************************************************************************************************************************

Q2. If we have pointer 

    struct point* ptr = &p1;
    
   With p1 as
   
    struct point{
    double x;
    double y;
    } p1 = { 2.5, 4.0};
    
   Then ptr->y has the value
   
ANS. 4.0

//*y is assigned to 4.0

********************************************************************************************************************************************

Q3. Which is a basic elementary operation for a stack

ANS. Empty

//*returns stack to empty state


********************************************************************************************************************************************

Q4. In the code snippet

    struct point{
    double x;
    double y;
    } p1 = { 4, 4.0};

    printf("%f\n", p1.x);
    
   What gets printed?
   
ANS. 4.000000

//*double using the %f format specifier i.e. upto 6 decimal places

********************************************************************************************************************************************

Q5. in the code snippet

    struct point{
    double x;
    double y;
    } p1 = {2.5, 4.0};

    printf("%f\n", p1.x);
    
   What gets printed?
   
ANS. 2.500000

//*%f format specifier i.e. upto 6 decimal places

********************************************************************************************************************************************

Q6. If we have pointer 

    struct point* ptr = &p1;
   
   With p1 as
   
    struct point{
    double x;
    double y;
    } p1;
    
   Then ptr->y has the value
   
ANS. 0.0

//*doubles x and y are initialized to 0, when we typed p1

********************************************************************************************************************************************

Q7. If we have pointer 

    struct point* ptr = &p1;
    
   With p1 as
    
    struct point{
    double x;
    double y;
    } p1 = {2.5};
    
   Then ptr->x has the value
    
ANS. 2.5

//*In this case, x is assigned to 2.5 while y is initialized to 0

********************************************************************************************************************************************

Q8. What operation would you use to add something onto a stack?

ANS. Push

//*adds new items to the stack

********************************************************************************************************************************************

Q9. If we push all the elements of the array int data[20]; onto a stack – the element at the bottom of the stack is

ANS. data[0]

//*This was the first element added, so it is at the bottom. Example of LIFO (Last In First Out)

********************************************************************************************************************************************

Q10. If we have pointer 

    struct point* ptr = &p1;
    
   With p1 as
   
    struct point{
    double x;
    double y;
    } p1 = {4, p1.x};
    
   Then ptr->y has the value

ANS. 4

//*y is given the value of x which is 4. y is declared as a pointer to x, thus ptr-> y points to y, which then points to x i.e. double 4

********************************************************************************************************************************************
