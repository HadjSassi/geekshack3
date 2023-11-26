n, z = map(int, input().split())
one=[]
two=[]
for i in range(n):
    while True:
        a, b = map(int, input().split())
        one.append(a)
        two.append(b)
        break
c=0
starcount=0
while c<z and one.index(min(one))!= two.index(min(two)):
    if z-c==1:
        starcount+=1
        c+=min(one)
    elif z-c==2:
        starcount+=2
        c+=min(two)
    elif z-c>=3  :
        c+= (min(one)+min(two))
        starcount+=3
print(c)
