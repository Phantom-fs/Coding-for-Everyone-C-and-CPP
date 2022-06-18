QUIZ-4 Answers with Reasoning

********************************************************************************************************************************************

Q1. To print \ on the screen in printf use

ANS. Another \

//*Escape the backslash by using another backslash*

********************************************************************************************************************************************

Q2. The second argument of fscanf() is

ANS. A C string that contains one or more of the following items − Whitespace character, Non-whitespace character and Format specifiers.

//*format = fscanf(data, "%d", &...to store); where data is the pointer to file (i.e, FILE *data)*

********************************************************************************************************************************************

Q3. In the code

    while(fscanf(ptr,”%d”,&d[*size]) == 1)
    
   Which conditions will terminate the while loop?
   
ANS. fscanf reaches the end of the file pointed to by ptr

//*or also when the file pointed to is NULL or empty file*

********************************************************************************************************************************************

Q4. What is the value of argc for the command line arguments

    ./a.out file-in file-out
    
ANS. 3

//*value of argc is the number of command line arguments excluding the executable (./a.out) eg. inputfile outputfile*

********************************************************************************************************************************************

Q5. Which statement will print "\n" to the screen?

ANS. printf("\\n");

//*escape using an extra backslash*

********************************************************************************************************************************************

Q6. What comes after the second argument of fscanf()?

ANS. Any necessary values to be substituted into format specifiers in the second argument

//*format = fscanf(data, "%d", &...to store); where data is the pointer to file (i.e, FILE *data)*
//CODE EXAMPLE:

    int i;
    i = 1;
    fscanf(ptr, "%d\n", i);
    
********************************************************************************************************************************************

Q7. -1 represents which value?

ANS. end of file (EOF)

//*-1 represents end of file*

********************************************************************************************************************************************

Q8. Is the value 

    in
    
   with a declaration of 
   
    FILE* in;
    
   a valid first argument for fscanf?
   
ANS. Yes, because it is a pointer to a file

//*first argument of fscanf() is a pointer to a file*

********************************************************************************************************************************************

Q9. To print %d on the screen use

ANS. printf("%%d");

//*escape the % to be printed by using another %*

********************************************************************************************************************************************

Q10. The value of argc for the command line statement
   
    ./a.out in out reversed capitalized

ANS. 5

//*value of argc is the number of command line arguments excluding the executable (./a.out) eg. inputfile outputfile*

********************************************************************************************************************************************
