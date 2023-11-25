while True:
    n, z = map(int, input().split())
    if (1 <= n <= 300000 and 1 <= z <= 2 * n): #z kadech mn star hachti
        break

one=[]
two=[]
for i in range(n):
    while True:
        a, b = map(int, input().split())
        one.append(a)
        two.append(b)
        break

starcount=0
move=0
if z%2==0:
    min_numb_of_levels=z/2
else :
    min_numb_of_levels = (z / 2)+1
max_numb_of_levels=len(one)

c=0

if n==min_numb_of_levels:
    for i in two:
        c+=i
    print(c)
elif n==max_numb_of_levels:
    for i in one:
        c+=i
    print(c)
else:
    if z-c !=0:
        if
        for i in range(n-1):
            minA=min(one)
            minB=min(two)
            if one.index(minA)!=two.index(minB):


