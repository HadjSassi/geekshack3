t=int(input())
for _ in range(t):
    n,p,k=map(int,input().split())
    arr=[int(x) for x in input()]
    x,y=map(int,input().split())
    ans=float("inf")
    l=1
    for i in range(p-1,(p+k)-1):
        cnt=0
        for j in range(n-l,p-2,k*-1):
            if arr[j] == 0:
                cnt+=1
            ans=min(abs((j+1)-(p))*y+cnt*x,ans)
        l+=1
    print(ans)
    