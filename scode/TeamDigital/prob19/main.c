#include<stdio.h>

int main(){
    printf("Bonjour TeamDigital !\nAllez, c'est à vous ! Bon courage ! ^_^");
    return 0;
} 
typedef enum suit 
{
	Club, Spade, Heart, Diamond
} Suit;

typedef enum rank 
{
	Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace 
} Rank ;

struct card
{
Suit c_suit;
Rank c_rank;
} Card;
card Deck[72];
