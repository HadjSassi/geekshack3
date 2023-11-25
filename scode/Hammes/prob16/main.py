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
global result;
result = 0;
def visit(city,roads,d,n,max):
    global result
    for i in range(n) :
        if roads[city][i] > 0:
            if max == d+roads[city][i]:
                result += 1 
            elif max > d+roads[city][i]:
                visit(i,roads,d+roads[city][i],n,max)
visit(s-1,city,0,n,i)
print(result) 