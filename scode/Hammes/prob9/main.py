from math import sqrt


def ra(p2):
    return sqrt(pow(p2[0],2)+pow(p2[1],2))



a , i = input().split()
a = int(a)
i = int(i)
la =[]
li  =[]
for k in range(a):
    la.append(input().split())
for k in range(i):
    li.append(input().split())
la = list(map(lambda x:list(map(lambda y:int(y),x)),la))
li = list(map(lambda x:list(map(lambda y:int(y),x)),li))

la = list(map(lambda x:ra(x),la))
li = list(map(lambda x:ra(x),li))
la.sort()
li.sort()
if (len(la)==0 or len(li)==0):
    print("YES")
elif la.pop(0)>li.pop() or la.pop()<li.pop(0):
    print("YES")
else :
    print("NO")
