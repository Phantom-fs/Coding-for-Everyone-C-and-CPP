QUIZ-5 Answers with Reasoning

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

//*In enum assigning means to provide the hidden value, thus here the next term's value after initialized
  *term is next number arriving after it* 

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

Q9. Q8. The code

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
  
  













