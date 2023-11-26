def lenlist(piles):
    t=False
    for i in piles:
        if len(i)!=0:
            t=True
            return (t)
    return (t)


def remove_max_for_bachka(piles):
    l=[]
    for pile in piles:
        if len(pile)!=0:
            l.append(pile[0])
            maxx=max(l)
            ind=l.index(max(l))
            return(piles[ind].pop(0))
        else:
            piles.pop(piles.index(pile))
            return 0

def remove_max_for_mabrouk(piles):
    l = []
    for pile in piles:
        if len(pile) != 0:
            l.append(pile[-1])
            maxx = max(l)
            ind = l.index(max(l))
            return (piles[ind].pop(-1))
        else:
            piles.pop(piles.index(pile))
            return 0

def optimal_game_score(n, piles):
    bachka = 0
    mabrouk = 0
    mb,mm=[],[]
    l1,l2=[],[]
    while lenlist(piles):
        bachka+=remove_max_for_bachka(piles)
        mabrouk+=remove_max_for_mabrouk(piles)
    return bachka, mabrouk

n = int(input())

piles = []
for i in range(n):
    pile = list(map(int, input().split()))[1:]
    piles.append(pile)

bachka_score, mabrouk_score = optimal_game_score(n, piles)
print(bachka_score,mabrouk_score)
