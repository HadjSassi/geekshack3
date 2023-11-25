n = int(input()) 
piles = [] 
for i in range(n): 
    pile = list(map(int, input().split()))[1:] 
    piles.append(pile) 
bachka_score = 0 
mabrouk_score = 0 
while any(piles): 
    for i in range(n): 
        if piles[i]: 
            bachka_card = piles[i].pop(0) 
            bachka_score += bachka_card 
            break 
    for i in range(n-1, -1, -1): 
        if piles[i]: 
            mabrouk_card = piles[i].pop() 
            mabrouk_score += mabrouk_card 
            break 
print(bachka_score, mabrouk_score)