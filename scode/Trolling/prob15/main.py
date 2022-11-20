n=int(input())
mp=[]
sqr_s=[[1,2,3,4],[4,1,2,3],[3,4,1,2],[2,3,4,1],[1,4,3,2],[2,1,4,3],[3,2,1,4],[4,3,2,1,]]
for i in range(n):
    s=input()
    L=s.split(" ")
    if '' in L:
        L.remove('')
    if '\r' in L:
        L.remove('\r')
    mp.append([int(k) for k in L])
cnt=0
for i in range(n-1):
    for j in range(len(mp[i])-1):
        sqr=[mp[i][j],mp[i][j+1],mp[i+1][j+1],mp[i+1][j]]
        if sqr in sqr_s:
            cnt+=1
print(cnt)
        