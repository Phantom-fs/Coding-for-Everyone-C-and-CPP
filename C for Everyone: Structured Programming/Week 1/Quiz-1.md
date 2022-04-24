QUIZ-1 Answers withReasoning

********************************************************************************************************************************************

Q1. What is the value of false in the following enum declaration:
      enum fuzzy_logic{ false, true, maybe};

ANS. None of the above

//According to the enum declaration
  false = 0 (Decleartion starts from 0)
  true = 1
  maybe = 2 

********************************************************************************************************************************************

Q2. What is the value printed by the following code snippet?

       #include <stdio.h>

       int main()
       {
       enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    
       enum month next_month(enum month m)
       {
        return((m + 1) % 12);
       }
    
       printf("%u\n", next_month(dec));

       return 0;
       }

ANS. 0

//dec is 11, so (11 + 1) % 12 = 0, which represents jan (0)

********************************************************************************************************************************************

Q3. If we use an assertion as in
        assert(cond1 && cond2);
    and cond1 is 1 then

ANS. If cond2 is 1 the program keeps running.

//cond1 is true so program checks to see if cond2 is also true (1) and continues to run if it is.

********************************************************************************************************************************************

Q4. What is the value of true in the enum declaration?
        enum fuzzy_logic{ false, true, maybe};

ANS. 1

//According to the enum declaration
  false = 0 (Decleartion starts from 0)
  true = 1  (ANS)
  maybe = 2  

********************************************************************************************************************************************

Q5. What is the value of true in the enum declaration?
         enum fuzzy_logic{ false, maybe, true};
         
ANS. 2   

//According to the enum declaration
  false = 0 (Decleartion starts from 0)
  maybe = 1
  true = 2  (ANS)

********************************************************************************************************************************************

Q6. If we use an assertion as in
         assert(cond1 || cond2);
         
 ANS. If cond2 is 1 the program keeps running.   
 
 //we are testing to see if EITHER cond1 or cond2 is true, so even if cond1 is 0 we must still test for cond2

********************************************************************************************************************************************

Q7. If we use an assertion as in
         assert(cond1 || cond2); 
         
ANS. The program keeps running

//Only one of either cond1 or cond2 needs to be evaluated as true, and since this is already the case for cond1.
  the program does not test for cond2 due to short-circuit evaluation and keeps running

********************************************************************************************************************************************

Q8. What is the value printed by the following code snippet?
         
         #include <stdio.h>

         int main()
         {
         enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    
         enum month get_month(enum month m)
         {
         return(m);
         }
    
         printf("%u\n", get_month(apr));

         return 0;
         }

ANS. 3

//as per enum declaration:
  jan = 0 (Decleartion starts from 0)
  feb = 1
  mar = 2
  apr = 3 (ANS)

********************************************************************************************************************************************

Q9. What is the value printed by the following code snippet?

         #include <stdio.h>

         int main()
         {
         enum month{jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
    
         enum month next_month(enum month m)
         { 
         return((m + 1) % 12);
         }
    
         printf("%u\n", next_month(dec + 1));

         return 0;
         }

ANS. 1

//dec is 11, m = 11+1 = 12 
  (12 + 1) % 12 = 1

********************************************************************************************************************************************

Q10. If we use an assertion as in
         assert(cond1 && cond2); 
         
ANS. cond2 is not evaluated and the program aborts

//As Cond1 is flase, and for logical && operator, we need both values to be 1. Using Short-Circuit evaluation, Program ends

********************************************************************************************************************************************
