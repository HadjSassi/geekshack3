def calculate_score(cards):
    score = 0
    card_count = {}
    suit_cards = {}

    for card in cards:
        value, suit = card[1:], card[0]

        card_count[value] = card_count.get(value, 0) + 1

        if suit not in suit_cards:
            suit_cards[suit] = [value]
        else:
            suit_cards[suit].append(value)

    for count in card_count.values():
        if count == 3:
            score += 6
        elif count == 4:
            score += 12

    for values in suit_cards.values():
        values.sort()
        for i in range(len(values) - 2):
            for j in range(i + 1, len(values) - 1):
                for k in range(j + 1, len(values)):
                    if values[k]=="J":
                        values[k]==10
                    if int(values[k]) - int(values[j]) == int(values[j]) - int(values[i]) == 1:
                        score += 9

    return score

def can_achieve_score(cards):
    max_score = 0

    for r in range(3, 5):
        for i in range(len(cards)):
            for j in range(i + 1, len(cards)):
                for k in range(j + 1, len(cards)):
                    if r == 4:
                        for l in range(k + 1, len(cards)):
                            current_score = calculate_score([cards[i], cards[j], cards[k], cards[l]])
                            max_score = max(max_score, current_score)
                    else:
                        current_score = calculate_score([cards[i], cards[j], cards[k]])
                        max_score = max(max_score, current_score)

    return max_score > 72, max_score

hand = input().split()

possible, max_score = can_achieve_score(hand)

if possible:
    print("YES", max_score)
else:
    print("NO")