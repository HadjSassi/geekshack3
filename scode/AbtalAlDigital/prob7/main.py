n, z = map(int, input().split())
l1= []
l2 = []

etoile = 0
for i in range(n):
    a, b = map(int, input().split())
    l1.append(a)
    l2.append(b)

l3=l1
l4=l2
l1.sort()
l2.sort()
resultat = 0
i = 0
j = 0
while (z - etoile > 2):
    if j<len(l1)-3 and l2[i] > l1[j] + l1[j + 1]:

        etoile += 2
        resultat += l1[j] + l1[j + 1]
        l2.remove(l4[l3.index(l1[j])])
        l2.remove(l4[l3.index(l1[j+1])])

        j += 2
    else:

        etoile += 2
        resultat += l2[i]
        l1.remove(l3[l4.index(l2[i])])
        i += 1

if z - etoile == 1:
    resultat += l1[j]



elif z - etoile == 2:
    if j<len(l1)-2 and l2[i] > l1[j] + l1[j+1]:
        resultat += l1[j] + l1[j+1]
    else:
        resultat += l2[i]

print(resultat)



