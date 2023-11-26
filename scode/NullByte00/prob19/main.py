import re
s = input().split()
cards = [i[1::] for i in s]

for i in range(len(cards)):
    if cards[i] in {'J', 'Q', 'K'}:
        cards[i] = 10
    elif cards[i] == 'A':
        cards[i] = 1

cards = [int(i) for i in cards]

somme = sum(cards)
if somme>72:
    print("YES", somme)
else:
    print("NO")  