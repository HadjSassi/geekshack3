#include<stdio.h>
int main(){
card Deck[72];
card topCard = Deck[0];
card bottomCard = Deck[72];

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
