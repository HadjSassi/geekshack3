from collections import Counter

def calculate_score(hand):
    card_counts = Counter(hand)

    score = 0

    for count in card_counts.values():
        if count == 3:
            score += 3
        elif count == 4:
            score += 4

    royal_count = 0
    for value in ['A', 'K', 'Q', 'J']:
        if value in card_counts:
            royal_count += 1

    if royal_count == 4:
        score += 10

    if score > 72:
        score = 84

    return score
def main():
    # Input: A list of space-separated strings representing the 14 cards
    cards = input().split()

    max_score = calculate_score(cards)

    # Output the result
    if max_score > 72:
        print(f"YES {max_score}")
    else:
        print("NO")

if __name__ == "__main__":
    main()