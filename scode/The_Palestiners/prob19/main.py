from itertools import combinations

def calculate_score(cards):
    score = 0
    for combo in cards:
        if len(set(combo)) == 1:  # 3 or 4 of a kind
            score += sum(combo)
        elif all(card[1] == combo[0][1] for card in combo):  # Straight
            score += sum(card[0] for card in combo)
    return score

def is_possible_to_score(cards):
    max_score = 0

    for r in range(3, 5):
        for combo in combinations(cards, r):
            max_score = max(max_score, calculate_score(combo))

    return max_score > 72, max_score

# Input
hand = input().split()

# Check possibility and calculate the highest achievable score
possible, max_score = is_possible_to_score(hand)

# Output
if possible:
    print("YES")
    print(max_score)
else:
    print("NO")

