public class Card {

public final static int SPADES = 0,
        HEARTS = 1,
        DIAMONDS = 2,
        CLUBS = 3;

public final static int ACE = 1,
        JACK = 11,
        QUEEN = 12,
        KING = 13,
        JOKER = 0;

private final int suit;

private final int value;

public Card(int theValue, int theSuit) {
    value = theValue;
    suit = theSuit;
}

public int getSuit() {
    return suit;
}

public int getValue() {
    return value;
}

public String getSuitAsString() {
    switch ( suit ) {
        case SPADES:   return "Spades";
        case HEARTS:   return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS:    return "Clubs";
        default:       return "??";
    }
}

public String getValueAsString() {
    switch ( value ) {
        case 1:   return "Ace";
        case 2:   return "2";
        case 3:   return "3";
        case 4:   return "4";
        case 5:   return "5";
        case 6:   return "6";
        case 7:   return "7";
        case 8:   return "8";
        case 9:   return "9";
        case 10:  return "10";
        case 11:  return "Jack";
        case 12:  return "Queen";
        case 13:  return "King";
        default:  return "JOKER";
    }
}

@Override
public String toString() {
    return getValueAsString().equals("JOKER") ? "JOKER" : getValueAsString() + "(" + getSuitAsString() + ")";
}

@Override
public boolean equals(Object card) {
    return suit == ((Card) card).getSuit() && value == ((Card) card).getValue();
}
}

private List<List<Card>> getSequences(List<Card> hand, int min) {
    List<List<Card>> sequences = new ArrayList<>();
    List<Card> sequence = new ArrayList<>();
    for(int i=1; i<hand.size(); i++) {
        if(hand.get(i).getSuit() == hand.get(i-1).getSuit() &&
                (hand.get(i).getValue() - hand.get(i-1).getValue()) == 1) {
            sequence.add(hand.get(i-1));
            if(hand.get(i).getValue() == 13) {
                int j = i;
                while(hand.get(j).getSuit() == hand.get(i).getSuit()) {
                    j--;
                    if(hand.get(j).getValue() == 1) {
                        sequence.add(hand.get(j));
                    }
                }
            }
            if(i == hand.size() -1) {
                sequence.add(hand.get(i));
                sequences.add(sequence);
            }
        } else {
            sequence.add(hand.get(i-1));
            if(sequence.size() >= min) {
                sequences.add(sequence);
            }
            sequence = new ArrayList<>();
        }
    }
    return sequences;
}

private List<List<Card>> getSets(List<Card> hand, int min) {
    List<List<Card>> sets = new ArrayList<>();
    List<Card> set = new ArrayList<>();
    for(int i=1; i<hand.size(); i++) {
        if(hand.get(i).getValue() != joker.getValue()) {
            if(hand.get(i).getValue() == hand.get(i-1).getValue()) {
                set.add(hand.get(i-1));
                if(i == hand.size() -1) {
                    set.add(hand.get(i));
                }
            } else {
                set.add(hand.get(i-1));
                if(set.size() >= min) {
                    sets.add(set);
                }
                set = new ArrayList<>();
            }
        }
    }
    return sets;