
def jouer(stacks,taille , p,n):
    max = 0
    i = 0
    for s in range(n):
        if taille[s] > 0 :
            if int(stacks[s][p]) > max:
                max = int(stacks[s][p])
                i = s

    taille[i] -= 1

    return int(stacks[i].pop(p))




n = int(input())
stacks = []
taille = []
for i in range(n):
    lista = input().split()
    taille.append(int(lista[0]))
    stacks.append(lista[1::])
bachka = 0
mabrouk = 0
while(sum(taille)):
    bachka += jouer(stacks,taille,0,n)
    if sum(taille) :
        mabrouk += jouer(stacks, taille, -1, n)
print(bachka, mabrouk)