
def maximize_score(n, piles):
    bachka_score = 0
    mabrouk_score = 0

    for i in range(n):
        if i % 2 == 0:  # Bachka's turn (0-based index)
            bachka_score += sum(piles[i])
        else:  # Mabrouk's turn
            mabrouk_score += sum(piles[i])

    print(bachka_score, mabrouk_score)

# Input reading
n = int(input())
piles = []

for _ in range(n):
    pile = list(map(int, input().split()[1:]))
    piles.append(pile)

# Call the function with the input values
maximize_score(n, piles)

