n = int(input())
l = []
for i in range(n):
    l.append ( list(map(lambda x:int(x),input().split())))
l2=[[0 for _ in range(n) ] for _ in range(len(l[i]))]
for i in range(n):
    for j in range(len(l[i])):
        l2[j][i]=l[i][j]
l2 = sorted(l2,key=lambda x:x[0])


def sim(l,n):
    time=0
    ret=[0 for i in range(n)]
    for index in range(len(l)-1) :
        time +=l[index][0]
        ma = 0
        for i in range(1,n):
            ret[i]+=l[index][i]-l[index+1][i-1]
            if ret[i]<0:
                ma=max(ma,abs(ret[i]))
                ret[i]=0
        time+=ma
    index = n-1
    mn = 0
    for i in range(n):
        mn += l[index][i]-ret[i]
    return time+mn



print(sim(l2,n))

    
          