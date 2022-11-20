
l=[]
n=int(input())
for i in range(n):
    #l1=map(int,input().split(' '))
    l1=input().split(' ')
    #print(l1)
    if(l1[-1]==''or l1[-1]=='\r'):
        l1.pop(-1)
    l1=[int(i) for i in l1]
    m=len(l1)
    l.append(l1)

possible_cases=[[[1,2],[4,3]],[[4,1],[3,2]],[[3,4],[2,1]],[[2,3],[1,4]],[[2,1],[3,4]],[[1,4],[2,3]],[[4,3],[1,2]],[[3,2],[4,1]]]
sum=0
for i in range(n-1):
    for j in range(m-1):
        l1=l[i][j:j+2]
        l2=l[i+1][j:j+2]
        l3=[l1,l2]
        if(l3 in possible_cases):
            sum+=1
print(sum)