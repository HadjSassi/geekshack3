n,m,s=map(int,input().split())
i=0
l=[]
while i< m :
    v,u,w=map(int,input().split())
    l.append(list((v,u,w)))
    i+=1
L=int(input())
def search(dis1,dis2,target) :
    if dis1+dis2==target :
        return 1
    else  :
        return 0

result=0
for i in range(len(l)) :
    if l[i][2]>=L  :
        result+=1
    elif l[i][0]==s or l[i][1]==s :
        for j in range(len(l)):
            result+=search(l[i][2],l[j][2],L)
print(result//2)