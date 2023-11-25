n,m,s = input().split()
n=  int(n)
m=  int(m)
s=  int(s)
city   = [[0 for j in range(n)] for i in range(n)]
for i in range(m):
    x,y,d= input().split()
    x=  int(x)
    y=  int(y)
    d=  int(d)
    city[x-1][y-1]=d
i = int(input())
global result
global incity
global inroad
incity = []
inroad = []
result = 0
def visit(city,roads,d,n,max):
    global result
    global incity
    global inroad
    for i in range(n) :
        if roads[city][i] > 0:
            if max == d+roads[city][i] and i not in incity:
                result += 1 
                incity.append(i)
            elif max > d+roads[city][i]:
                visit(i,roads,d+roads[city][i],n,max)
            else :
                if max-d != roads[city][i]/2 :
                    result += 1
                    inroad.append(str(city)+":"+str(max-d))
                elif city+":"+max-d not in inroad :
                    result += 1
                    inroad.append(str(city)+":"+str(max-d))

visit(s-1,city,0,n,i)
print(result)