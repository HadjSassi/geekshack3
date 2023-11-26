def calculate_score(hand):
    score = 0
    card_count = {}
    suit_count = {}

    for card in hand:
        value, suit = card[0], card[1:]
        card_count[value] = card_count.get(value, 0) + 1
        suit_count[suit] = suit_count.get(suit, 0) + 1
    #print(card_count, suit_count)
    for count in card_count.values():
        if count == 3:
            score += 30
        elif count == 4:
            score += 40
    #print(score)
    for suit, count in suit_count.items():
        if count >= 3:
            values = [int(card[1:]) if card[1:].isdigit() else 10 for card in hand if card.endswith(suit)]
            values.sort()
            #print(values)
            for i in range(len(values) - 2):
                if values[i] == values[i + 1] == values[i + 2]:
                    if not(i > 1 and values[i + 1] == values[i]):
                        score += values[i]
                    else :
                        score += values[i]*4

                    #print(score)



    return score

hand = input().split()
score = calculate_score(hand)
if score > 72:
    print("YES",score)
else:
    print("NO")