/*
Cards program supporting their type and number with multiple different methods of dealing, shuffling, finding probability etc. 
*/
//Advanced level C program with multiple code snippet from online sources
//SHORTER VERSION
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define DECK_SIZE 52    //to be used to randomly select each of 52 cards
#define SUITS_PLUS_ONE 5    //to be used to generate any of the 4 suits
#define PIPS_PLUS_ONE 14    //to be used to generate any of the 13 pips
#define DECKS_NUMBER 200000 //this * 7 hands per deck = 1.4 million hands
#define HANDS_NUMBER 1400000
#define HAND_SIZE 7

typedef enum suit
{
    hearts,
    diamonds,
    spades,
    clubs
} suit;

typedef struct playing_card
{
    suit suit;
    short pip;
} card;

card * shuffles_deck(card * ptr_to_deck, card * ptr_to_shuffled)    //shuffles the deck
{     
    int element_numbers[52]; //keeps track of selected cards to avoid repetition
    int value = 53;  //use to initalize the above array with number > 52
    
    for(int m = 0; m < 52; m++)
    {
        element_numbers[m] = value; //filling the array with value not in deck
    }
    
    for(int i = 0; i < 52; i++)
    {
        int which_element = rand() % DECK_SIZE;
        int original_i = i;  // to keep track of i's value so far
        for(int k = 0; k < 52; k++)
        {
            if(element_numbers[k] == which_element)  //ie: if card drawn before
            {
                i--;
            }
        }
           
        if(original_i == i)  //if i wsn't decremented = card not drawn before 
        {   
            element_numbers[i] = which_element;
            *(ptr_to_shuffled + i) = *(ptr_to_deck + which_element); 
        }    
     }

     return ptr_to_shuffled;
}
            
card * deals_hand(card * ptr_to_hand, card * ptr_to_shuffled)   //deals each hand and organizes cards by ascending pip value
{
    static int j = 0;
    int i = 0;
    card swapper_card;
    for( ; i < 7; i++)
    {
        *(ptr_to_hand + i) = *(ptr_to_shuffled + j);
        j++;
    }
    
    for(int index = 0; index < 7; index++)
    {
        for(int k = 0; k < 6; k++)
        {
            if((ptr_to_hand + (k+1))->pip < (ptr_to_hand + k)->pip)
            {
                swapper_card = *(ptr_to_hand + (k+1));
                *(ptr_to_hand + (k+1)) = *(ptr_to_hand + k);
                *(ptr_to_hand + k) = swapper_card;
            }
        } 
        if((ptr_to_hand + 6)->pip >= (ptr_to_hand + 5)->pip && (ptr_to_hand + 5)->pip >= (ptr_to_hand+4)->pip &&
           (ptr_to_hand + 4)->pip >= (ptr_to_hand + 3)->pip && (ptr_to_hand + 3)->pip >= (ptr_to_hand + 2)->pip &&
           (ptr_to_hand + 2)->pip >= (ptr_to_hand + 1)->pip && (ptr_to_hand + 1)->pip >= (ptr_to_hand + 0)->pip)
        {
            break;
        }

    }

    if(j == 49)  // meaning if j has reached the 50th card after which there is no more complete hand to be drawn from the deck
    {
        j = 0;
    }
    return ptr_to_hand;
}

void hand_determinator( card * ptr_to_hand) //determines what each hand contains (er: no pair, pair, etc.)
{
    static int how_many_hands = 0; //when 1000005, calculate probabilities.
    
    static int no_pair = 0, one_pair = 0, three_of_kind = 0;
    static int two_pair = 0, four_of_kind = 0, full_house = 0;
    int first_type_counter = 1;
    int second_type_counter = 1;

    card *first_type = (card *) calloc(1, sizeof(card));
    card *second_type = (card *) calloc(1, sizeof(card));
    
    if(first_type == NULL || second_type == NULL)
    {
        exit(1);
    }

    how_many_hands ++; 
    if(how_many_hands < HANDS_NUMBER)
    {
        for(int i = 0; i <HAND_SIZE; i++)
        {              
            if( (second_type + 0)->pip == 0)   //since calloc will initialize the pip value with 0          
            {
                
                if(i == 0)
                {
                    *(first_type + 0) = *(ptr_to_hand + i);
                }
                else
                {
                    if( (first_type + 0)->pip == (ptr_to_hand + i)->pip)
                    {
                        first_type_counter ++;
                        first_type = realloc(first_type, first_type_counter * sizeof(card));
                        *(first_type + (first_type_counter - 1)) = *(ptr_to_hand + i);
                    }
                    else
                    {
                        if(first_type_counter == 1)
                        {
                            *(first_type + 0) = *(ptr_to_hand + i);                            
                        }
                        else if(first_type_counter > 1)
                        {
                            *(second_type + 0) = *(ptr_to_hand + i);
                        }
                    }
                }
            }
            else
            {
                
                if( (second_type + 0)->pip == (ptr_to_hand + i)->pip)
                {
                    second_type_counter ++;
                    second_type = realloc(second_type, second_type_counter * sizeof(card));
                    *(second_type + (second_type_counter - 1)) = *(ptr_to_hand + i);
                }
                else
                {
                    if(second_type_counter == 1)
                    {
                        *(second_type + 0) = *(ptr_to_hand + i);
                    }
                    else if(second_type_counter > 1)
                    {
                        continue;
                    }
                }
            }
        }
            
        if(first_type_counter == 1 && second_type_counter == 1)
        {
            no_pair ++;
        }
        else if(first_type_counter == 2 && second_type_counter == 1)
        {
            one_pair ++;
        }
        else if(first_type_counter == 2 && second_type_counter == 2)
        {
            two_pair ++;
        }
        else if(first_type_counter == 3 && second_type_counter != 2 || first_type_counter != 2 && second_type_counter == 3)
        {
            three_of_kind ++;
        }
        else if(first_type_counter == 4 || second_type_counter == 4)
        {
            four_of_kind ++;
        }
        else if(first_type_counter == 3 && second_type_counter == 2 || first_type_counter == 2 && second_type_counter == 3) 
        {
            full_house ++;
        }   
    }                    
    else
    {
        double no_pair_prob = no_pair / (double)HANDS_NUMBER;
        double one_pair_prob = one_pair / (double)HANDS_NUMBER;
        double two_pair_prob = two_pair / (double)HANDS_NUMBER;
        double three_of_kind_prob = three_of_kind / (double)HANDS_NUMBER;
        double four_of_kind_prob = four_of_kind /(double)HANDS_NUMBER;
        double full_house_prob = full_house / (double)HANDS_NUMBER;

        printf("\n\nNo pair probablity =  %lf\nOne pair probability = %lf\nTwo pair probability = %lf\n" 
               "Three of a kind probablity = %lf\nFour of a kind probability = %lf\n"
               "Full house probability = %lf\n\n", no_pair_prob, one_pair_prob,
               two_pair_prob, three_of_kind_prob, four_of_kind_prob, full_house_prob);           
    }
        
    free(first_type);
    free(second_type);
}

int main(void)
{

    srand(time(0)); //seeding rand with current time

    card deck[52];
    card shuffled_deck[52];
    card hand[7];
    card one_card;
    static int i = 0;   //to represent the 52 cards
    //card * ptr_to_deck = deck;    
    //card * ptr_to_shuffled = shuffled_deck;
    //card * ptr_to_hand = hand;

    card * ptr_to_deck;
    card * ptr_to_shuffled;
    card * ptr_to_hand;


    for( int j = 1; j <= 13; j++)   //to generate all pip values
    {
        for(int k = 1; k <= 4; k++) //to generate all suits
        {
            one_card.suit = k;
            one_card.pip = j; 
            deck[i] = one_card;
            i++;
        }
    }
     

    for(int i  = 0; i < DECKS_NUMBER; i++)  //number of decks to exceed 1.4 M hands
    {
        ptr_to_shuffled = shuffles_deck(&deck[0], &shuffled_deck[0]); 
        for(int j = 0; j < 7; j++)
        {
            ptr_to_hand = deals_hand(&hand[0], &shuffled_deck[0]); 
            hand_determinator(&hand[0]);
        }
    }

    return 0;   
   
}
