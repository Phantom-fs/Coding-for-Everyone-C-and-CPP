/*
Cards program supporting their type and number with multiple different methods of dealing, shuffling, finding probability etc.
*/
//Advanced level C program with multiple code snippet from online sources
//Coder: Phantom-fs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

//defining main terms and their values

#define DECK_SIZE 52
#define HAND_SIZE 7
#define SUB_HAND 5
#define FLUSH 5
#define PIPS 13

#define KING 13
#define QUEEN 12
#define JACK 11
#define ACE 1

#define BIG_NUMBER 1000000

#define srand48(x) srand((unsigned)(x))
#define drand48() (rand()/(RAND_MAX + 1.0))

int sub_index = 0, count_hands = 0;

typedef enum { spades, hearts, clubs, diamonds} suit;    // Cards suits

typedef struct deck_card                                 // This struct defines a card in a standard deck
{
    short pips;     //value ranging from 1-13
    suit suit;      //from above enum data type
} card;

//Comparison method to the qsort() method used in is_straight()
int comp(const void *a, const void *b)
{
    card *a_card = (card *)a;
    card *b_card = (card *)b;
    return (a_card->pips - b_card->pips);
}

//Method for combinations
void get_combo(card combos[][SUB_HAND], card hand[], int s[]){
    card res[SUB_HAND];
    int i;
    for (i = 0; i < SUB_HAND; i++) {
        memcpy(&res[i], &hand[s[i]], sizeof(card));
    }
    memcpy(combos[sub_index++], res, SUB_HAND * sizeof(card));
}

//7 card hand and produces all 5 card subhands available (7 choose 5 = 21)
void combinations(card combos[][SUB_HAND], card hand[]){
    int s[SUB_HAND];
    int i;
    for(i = 0; (s[i] = i)<SUB_HAND-1; i++);
    get_combo(combos, hand, s);
    for(;;){
        int j;
        
        for(j = SUB_HAND-1; j >= 0 && s[j] == HAND_SIZE - SUB_HAND + j; j--)
        ;
            if(j<0)break;
            s[j]++;
            
        for(++j; j < SUB_HAND; j++){
            s[j] = s[j-1]+1;
        }
        get_combo(combos, hand, s);
    }
}


// This method takes a 5 card straight and returns true if the straight is a high straight (10 -> ACE)
int high_straight(card hand[]){
    int i, king_flag = 0, ace_flag = 0;
    for(i = 0; i<SUB_HAND; i++){
        if(hand[i].pips == KING) king_flag = 1;
        else if(hand[i].pips == ACE) ace_flag = 1;
    }
    return (king_flag && ace_flag);
}

//Gets a deck of cards and shuffles it
//Shuffle the deck based on a random seed taken from the user's time i.e. srand()
//Array shuffler credits at https://stackoverflow.com/questions/6127503/shuffle-array-in-c

int shuffle(card deck[])
{

    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);;

    int i;
    for (i = DECK_SIZE - 1; i > 0; i--)
    {
        size_t j = (unsigned int)(drand48() * (i + 1));
        card t = deck[j];
        deck[j] = deck[i];
        deck[i] = t;
    }
    return 0;
}

// This method fills the deck with standard poker cards
int init(card deck[])
{
    // Will represent card's pips
    short i;

    for (i = 1; i <= DECK_SIZE; i++)
    {
        // Fill the cards with 1-13
        deck[i - 1].pips = i % 13;
        if (!(i % 13))
            // If i%13 == 0, this card is a king
            deck[i - 1].pips = KING;
        if (i <= 13)
            deck[i - 1].suit = spades;
        else if (i <= 26)
            deck[i - 1].suit = hearts;
        else if (i <= 39)
            deck[i - 1].suit = clubs;
        else
            deck[i - 1].suit = diamonds;
    }
    return 0;
}

// This method prints len cards
int print_cards(card deck[], int len)
{

    int i;
    printf("*** Hand start *** \n");
    for (i = 0; i < len; i++)
    {
        short pip = deck[i].pips;
        switch (deck[i].suit)
        {
        case spades:

            switch (pip)
            {
            case ACE:
                printf("Ace of Spades\n"); break;

            case KING:
                printf("King of Spades\n"); break;

            case QUEEN:
                printf("Queen of Spades\n"); break;

            case JACK:
                printf("Jack of Spades\n"); break;

            default:
                printf("%d of Spades\n", deck[i].pips); break;

            } break;

        case hearts:

            switch (pip)
            {
            case ACE:
                printf("Ace of Hearts\n"); break;

            case KING:
                printf("King of Hearts\n"); break;

            case QUEEN:
                printf("Queen of Hearts\n"); break;

            case JACK:
                printf("Jack of Hearts\n"); break;
            default:
                printf("%d of Hearts\n", deck[i].pips); break;

            } break;

        case clubs:

            switch (pip)
            {
            case ACE:
                printf("Ace of Clubs\n");
                break;

            case KING:
                printf("King of Clubs\n");
                break;

            case QUEEN:
                printf("Queen of Clubs\n");
                break;

            case JACK:
                printf("Jack of Clubs\n");
                break;
            default:
                printf("%d of Clubs\n", deck[i].pips);
                break;

            } break;

        case diamonds:

            switch (pip)
            {
            case ACE:
                printf("Ace of Diamonds\n"); break;

            case KING:
                printf("King of Diamonds\n"); break;

            case QUEEN:
                printf("Queen of Diamonds\n"); break;

            case JACK:
                printf("Jack of Diamonds\n"); break;

            default:
                printf("%d of Diamonds\n", deck[i].pips); break;

            } break;
        }
    }

    printf("\n\n****** Hand %d end ****** \n\n", count_hands++);

    return 0;
}

//Gets a card deck and deals a hand of HAND_SIZE size

int deal_hand(card deck[], card hand[])
{
    // We shuffle the cards before dealing a hand
    shuffle(deck);

    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        memcpy(&hand[i], &deck[i], sizeof(card));
    }
    return 0;
}

//Check to see whether a hand has a pair in it
int is_pair(card hand[])
{
    //Init a counter array, each index represent a possible card pip
    int pips[PIPS] = {0};

    int i;
    
    //Searching the hand for a pair
    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            return 1;
    }

    return 0;
}

//Check to see whether a hand has at least two pairs in it
int is_two_pair(card hand[])
{
    int count = 0, pips[PIPS] = {0}, i;

    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 2)
            count++;
    }
    return (count >= 2);
}

//Checks to see whether a hand has three of a kind
int is_three(card hand[])
{
    //Init a counter array, each index represent a possible card pip
    int pips[PIPS] = {0}, i;

    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;

        // If this card appeared three times
        if (pips[hand[i].pips - 1] == 3)
            return 1;
    }

    // If we reached this part of the code, there is no three of a kind in this hand

    return 0;
}

// This method takes a 5 card hand and checks for a straight
int is_straight_5(card hand[]){

    // Sort the 5 card hand before checking
    qsort(hand, SUB_HAND, sizeof(card), comp);
    if(hand[0].pips == ACE && hand[4].pips == KING)
    {
        if(hand[1].pips == 10 && hand[2].pips == JACK && hand[3].pips == QUEEN)
            return 1;
        return 0;
    }
    else{
        // [1,2,3,4,5]
        int i;
        for(i = SUB_HAND-1; i >= 1; i--)
        {
            if((hand[i].pips - hand[i-1].pips) != 1) return 0;
        }
        return 1;
    }
}

// This method checks to see whether a hand has a staright in it.
int is_straight(int indices[])
{
    int i;
    for(i = 0; i<21; i++){
        if(indices[i]) return 1;
    }
    return 0;
}

// This methos takes all 21 combos of 5 card hands from the given 7 cards
// and marks the indices in which there is a straight
void find_straights(card combos[][SUB_HAND], int indices[]){
    int i;
    for(i = 0; i<21; i++)
    {
        if(is_straight_5(combos[i]))
            indices[i] = 1;
    }
}

// This method determines whether a hand has a flush in it
int is_flush(card hand[], int hand_size){

    int spades_count = 0;
    int hearts_count = 0;
    int clubs_count = 0;
    int diamonds_count = 0;

    int i, suit;
    for (i = 0; i < hand_size; i++)
    {
        suit = hand[i].suit;
        switch (suit)
        {

        case spades:
            spades_count++;
            if (spades_count == FLUSH)
                return 1;
            break;

        case hearts:
            hearts_count++;
            if (hearts_count == FLUSH)
                return 1;
            break;

        case clubs:
            clubs_count++;
            if (clubs_count == FLUSH)
                return 1;
            break;

        case diamonds:
            diamonds_count++;
            if (diamonds_count == FLUSH)
                return 1;
            break;
        }
    }
    return 0;
}

// This method determines whether a hand is a full house
int is_full_house(card hand[])
    {
    int pips[13], i;
    for(i = 0; i<13; i++){
        pips[i] = 0;
    }

    // For each possible pip, count the number of times it apperas in argument hand
    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
    }

    int pair_flag = 0, three_flag = 0;
      for (i = 0; i < 13; i++)
      {
        if (pips[i] == 2)
            pair_flag = 1;

        else if (pips[i] == 3)
            three_flag = 1;
      }
    return (pair_flag == 1 && three_flag == 1);
}

// This function checks to see whether a hand has four of a kind
int is_four(card hand[])
{
    int pips[13] = {0};
    int i;
    for (i = 0; i < HAND_SIZE; i++)
    {
        pips[hand[i].pips - 1]++;
        if (pips[hand[i].pips - 1] == 4)
            return 1;
    }
    return 0;
}

// This mehtod checks to see whether a hand is a straight flush
int is_straight_flush(card combos[][SUB_HAND], int indices[])
{

    int i;
    for(i = 0; i<21; i++){
        if(indices[i]){
            if(is_flush(combos[i], SUB_HAND)) return 1;
        }
    }
    return 0;
}

// This mehtod checks to see whether a hand is a royal flush
int is_royale_flush(card combos[][SUB_HAND], int indices[])
{
    int i;
    for(i = 0; i<21; i++){
        if(indices[i]){
            if(high_straight(combos[i])){
               if(is_flush(combos[i], SUB_HAND)) return 1;
            }
        }
    }
    return 0;
}

int main(void){

    double royal_flush = 0.0, straight_flush = 0.0, four_of_a_kind = 0.0, full_house = 0.0, flush = 0.0, straight = 0.0, three_of_a_kind = 0.0, two_pair = 0.0, pair = 0.0 , high_card = 0.0;
    // Initialize a standard deck and deal a random 7 card hand
    card deck[DECK_SIZE];
    init(deck);
    card hand[HAND_SIZE], combos[21][SUB_HAND];
    
    int i, j;
    int indices[21] = {0};
    for(i = 0; i<=BIG_NUMBER; i++)
    {
        
        deal_hand(deck, hand);
        //print_cards(hand, HAND_SIZE);
        
        // zero all indices marking locations of straights
        for(j = 0; j<21; j++){
            indices[j] = 0;
        }
        
        // Get all possible combinations (7C5) of that hand
        //card result[SUB_HAND];
        combinations(combos,hand);

        find_straights(combos, indices);

        if(is_royale_flush(combos, indices))
        {
            royal_flush++;
        }

        else if(is_straight_flush(combos, indices))
        {
            straight_flush++;
        }

        else if(is_four(hand))
        {
            four_of_a_kind++;
        }

        else if(is_full_house(hand))
        {
            full_house++;
        }

        else if(is_flush(hand, HAND_SIZE))
        {
            flush++;
        }

        else if(is_straight(indices))
        {
            straight++;
        }

        else if(is_three(hand))
        {
            three_of_a_kind++;
        }

        else if(is_two_pair(hand))
        {
            two_pair++;
        }

        else if(is_pair(hand))
        {
            pair++;
        }

        else high_card++;
            sub_index = 0;
    }
    
    printf("\n\n\n********************************************************\n\n");

    printf("\nRoyal Flush      -> %lf\n", royal_flush/BIG_NUMBER);
 
    printf("\nStraight Flush   -> %lf\n", straight_flush/BIG_NUMBER);

    printf("\nFour of a Kind   -> %lf\n", four_of_a_kind/BIG_NUMBER);

    printf("\nFull House       -> %lf\n", full_house/BIG_NUMBER);

    printf("\nFlush            -> %lf\n", flush/BIG_NUMBER);

    printf("\nStraight         -> %lf\n", straight/BIG_NUMBER);

    printf("\nThree of a Kind  -> %lf\n", three_of_a_kind/BIG_NUMBER);

    printf("\nTwo Pairs        -> %lf\n", two_pair/BIG_NUMBER);

    printf("\nPair             -> %lf\n", pair/BIG_NUMBER);

    printf("\nHigh Card        -> %lf\n", high_card/BIG_NUMBER);

    printf("\n\n\n********************************************************\n\n");

    return 0;
}

//source & inspiration for major part of code : talzich
//lINK : https://github.com/talzich/Coding-for-Everyone-C-and-CPP/blob/main/c_for_everyone_struct/week-2/week-2-honors.c
