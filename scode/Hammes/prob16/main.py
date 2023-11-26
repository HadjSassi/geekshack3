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
    city[y-1][x-1]=d
i = int(input())
global result
global incity
global inroad
global others
global visited
global visited_d
incity = []
inroad = []
result = 0
others = []
visited = []
visited_d = []
def visit(city,roads,d,n,max,fro):
    global result
    global incity
    global inroad
    global others
    global visited_d
    global visited
    visited.append([city,d])
    visited_d.append([city,fro])
    if d == max :
        return
    for i in range(n) :
        if roads[city][i] > 0 and i != fro:
            if max == d+roads[city][i] :
                if i not  in incity:
                    result += 1 
                    incity.append(i)              
            elif max > d+roads[city][i]:
                if [i,d+roads[city][i]] not in visited and [i,city] not in visited_d:
                    visit(i,roads,d+roads[city][i],n,max,city)
            else :
                if max-d != int(roads[city][i]/2) :
                    result += 1
                    others.append([city,i,max-d])
                elif sorted([city+1 , i+1]) not in inroad :
                    result += 1
                    inroad.append(sorted([city+1 , i+1]))



visit(s-1,city,0,n,i,-1)
print(result) 