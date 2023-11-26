from itertools import combinations

def calculate_score(cards):
    score = 0
    counts = {}
    suits = {}

    for card in cards:
        value, suit = card[:-1], card[-1]
        counts[value] = counts.get(value, 0) + 1
        suits[suit] = suits.get(suit, 0) + 1

    for count in counts.values():
        if count == 3:
            score += 6
        elif count == 4:
            score += 12

    for suit_count in suits.values():
        if suit_count >= 3:
            score += (suit_count * (suit_count + 1)) // 2

    return score

def can_achieve_score(cards):
    for subset_size in range(3, 5):
        for subset in combinations(cards, subset_size):
            subset_score = calculate_score(list(subset))
            if subset_score > 72:
                return True, subset_score

    return False, 0

def main():
    cards = input().split()

    possible, highest_score = can_achieve_score(cards)

    if possible:
        print(f"YES {highest_score}")
    else:
        print("NO")

if __name__ == "__main__":
    main()
