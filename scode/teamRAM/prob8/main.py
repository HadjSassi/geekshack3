def optimal_card_game_score(n, piles):
    bachka_score = 0
    mabrouk_score = 0

    for i in range(n):
        if i % 2 == 0:
            bachka_score += max(piles[i][0], piles[i][-1])
        else:
            mabrouk_score += max(piles[i][0], piles[i][-1])

    return bachka_score, mabrouk_score

n = int(input())
piles = []

for _ in range(n):
    pile_info = list(map(int, input().split()))
    pile = pile_info[1:]
    piles.append(pile)

bachka_score, mabrouk_score = optimal_card_game_score(n, piles)
print(bachka_score, mabrouk_score)