while True:
    n, z = map(int, input().split())
    if (1 <= n <= 300000 and 1 <= z <= 2 * n): #z kadech mn star hachti
        break

one_star=[]
two_star=[]
for i in range(n):
    while True:
        a, b = map(int, input().split())
        one_star.append(a)
        two_star.append(b)
        break

starcount=0
move=0

while starcount<z and len(one_star)!=0:
    minA=min(one_star)
    i_minA=one_star.index(minA)
    minB = min(two_star)
    i_minB =two_star.index(minB)
    one_star.pop(i_minA)
    two_star.pop(i_minB)
    if z-starcount>=3  and i_minA !=i_minB:
        starcount+=3
        move+= (minA+minB)
    elif 3>z-starcount>0 and i_minA !=i_minB:
        starcount+=2
        move+=minB
    elif 1<=z-starcount<2 and i_minA!=i_minB:
        starcount+=1
        move+=minA

print(move) 