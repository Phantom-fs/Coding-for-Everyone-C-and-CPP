QUIZ-6 (FINAL EXAM) Answers with Reasoning

********************************************************************************************************************************************

Q1. True/False: Switch is a keyword

ANS. True

********************************************************************************************************************************************

Q2. True/False: printf is a keyword 

ANS. False


//*printf is a function*

********************************************************************************************************************************************

Q3. True/False: ||  is the address operator

ANS. False


//*& also called amsersand is the address operator in C*

********************************************************************************************************************************************

Q4. True/False: EOF is a keyword  

ANS. False


//*Its like a special character with value -1*

********************************************************************************************************************************************

Q5. True/False: malloc is an operator

ANS. False


//*Its A function is used to assign a specified amount of memory, it also returns a pointer to the space allocated in 
  *memory using this function*
  
********************************************************************************************************************************************

Q6. The code snippet 
    
    typedef enum choices {left, left_center = 2, right_center, right = 5} choices
    
  The enumerator left has what value ? 
  
ANS. 0

 
//*In enum assigning means to provide the hidden value, thus here the value starts from 0*
  
********************************************************************************************************************************************

Q7. The enumerator right_center has what value? 

ANS. 3


//*Inside enum assigning means to provide the hidden value, thus here the next term's value after initialized
  *term is next number arriving after it, thus here after 2 comes 3*

********************************************************************************************************************************************

Q8. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    }

   For the code above, what is the value of the format specifier corresponding to the print statement " a && b =  "

ANS. 1

********************************************************************************************************************************************

Q9. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    }

  For the code above, what is the value of the format specifier corresponding to the print statement " b % a =   "
  
ANS. 1


//*Modulos operator*

********************************************************************************************************************************************

Q10. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    }
     
   For the code above, what is the value of the format specifier corresponding to the print statement " a /  b =  "

ANS. 0

********************************************************************************************************************************************

Q11. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement " 2 * a + 1 < b = "

ANS. 0

********************************************************************************************************************************************

Q12. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement "  b <= c    =  "

ANS. 1

********************************************************************************************************************************************

Q13. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement "  !!c  = "

ANS. 1

********************************************************************************************************************************************

Q14. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement "  c > 2 && a > 6 = "

ANS. 0

********************************************************************************************************************************************

Q15. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement "  b == 2 || a != 4 ="

ANS. 1

********************************************************************************************************************************************

Q16. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement " (a + b) * c-- ="

ANS. 56

********************************************************************************************************************************************

Q17. The code

    #include<stdio.h>
    int main()
    {
          int a = 2, b = 5, c = 8;
          
          printf("  a && b  = %d \n ",  a && b);
          printf(" b %% a   = %d \n ", b % a );
          printf(" a / b    = %d \n " , a/b); 
          printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
          printf(" b <= c = %d \n "  , b<= c);
          printf(" !!c = %d \n " , !!c); 
          printf(" c > 2 && a > 6 = %d \n " , c> 2 && a > 6); 
          printf(" b == 2||a != 4 = %d \n ", b == 2 || a != 4 );
          printf(" (a + b) * c-- = %d \n ",  (a + b) * c-- );
          printf(" c = ++b = %d \n ",c = ++b);  
          return 0;
    } 

   For the code above, what is the value of the format specifier corresponding to the print statement " c = ++b    = "

ANS. 6

********************************************************************************************************************************************

Q18. The sqrt() function returns

ANS. double

********************************************************************************************************************************************

Q19. The rand() function is declared in

ANS. stdlib.h


//*Used to create a random number based on seed*

********************************************************************************************************************************************

Q20. The function malloc() returns 

ANS. void*

********************************************************************************************************************************************

Q21. The array declaration double data[5][4]; will allocate storage for  

ANS. 20 doubles


//*Its an deceleration for matrix (2-D Array), thus the matrix have 5 * 4 elements i.e. 20 elements*

********************************************************************************************************************************************

Q22. In

    enum myfoods{butter = 2, milk = 5, cheese = 8, eggs};
    
   eggs is the int value
   
ANS. 9


//*Inside enum assigning means to provide the hidden value, thus here the next term's value after initialized
  *term is next number arriving after it, thus here after 8 comes 9*
  
********************************************************************************************************************************************  
  
Q23. In the code

    struct complex{ double real;  double imaginary;}  c1 = {  1.5,  -2.0}, c2; 
    struct complex * ptr_c = &c1;
    
   The value of c1.real is the same as:  
    
ANS. ptr_c ->real


//*as ptr_c is addressed to c1*

********************************************************************************************************************************************

Q24. The precedence of the operator  -> is  

ANS. higher than all of these (< , * , !)

********************************************************************************************************************************************

Q25. To find the kth element in an array versus the kth element in a linear list:

ANS. the array element look-up is faster by approximately some proportion to k


//*According to the speed, from fastest to slowest is : binary tree > array > linear list*

********************************************************************************************************************************************

Q26. In the code

    int mystery(LINK head)
       {
           if (head == NULL)
               return 0;
               
           else
               return( 1 + count(head -> next));
       }

   This code:
   
ANS. counts the elements of a list

********************************************************************************************************************************************

Q27. In the code

    FILE *ofp;
    fopen("temp", "w+");
    
ANS. temp is a file in the local directory

********************************************************************************************************************************************

Q28. Who created C++ ? 

ANS. Stroustrup


//*C++ was developed by Bjarne Stroustrup of Bell Laboratories in the early 1980s*

********************************************************************************************************************************************

Q29. In C++  which keyword has a significantly different meaning than in C?

ANS. auto


//*auto means deduce the type of the adjacent variable name*

********************************************************************************************************************************************

Q30. In the conversion specification

    %6lf 
    
   The 6 means

ANS. field width is 6


//*Its like upto 6 decical places in double type*

********************************************************************************************************************************************
