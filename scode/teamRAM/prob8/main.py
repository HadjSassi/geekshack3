while True:
    n=int(input()) #nb de pile
    if (1<=n<=100):
        break
mabrouk=0
bachka=0
def lenlist(piles):
    t=False
    for i in piles:
        if len(i)!=0:
            t=True
            return (t)
    return (t)

piles=[]
for i in range(n):
    l=[]
    nb_el=int(input())
    l.append(nb_el)
    for j in range(nb_el):
        l.append(int(input()))
    piles.append(l)

#dibit di jeu
if len(piles)==1:
    l=piles[0]
    l.pop(0)
    if len(l)%2==0:
        for i in range(len(l)/2):
            bachka+=l.pop(i)
        for i in l:
            bachka+=i
    else:
        if len(l) % 2 == 0:
            for i in range((len(l) / 2)+1):
                bachka += l.pop(i)
            for i in l:
                bachka += i
else:
    c=True
    while lenlist(piles) and len(piles)!=0:
        lb=[]
        lm=[]
        for i in piles:
            if len(i)==0:
                piles.pop(piles.index(i))
            else:
                lb.append(i[0])
                lm.append(i[len(i)])
        maxB=max(lb)
        iB=lb.index(maxB)
        bachka+=piles.pop(piles[iB][0])
        maxM = max(lm)
        iM = lm.index(maxM)
        mabrouk+=piles.pop(piles[iM][len(piles[iM])])
print(bachka, mabrouk)
