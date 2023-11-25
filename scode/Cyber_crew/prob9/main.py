n,m=map(int,input().split())
l1=[]
for i in range (n):
    a,b=map(int,input().split())
    l1.append([a,b])
l2=[]
for j in range(m):
    a,b=map(int,input().split())
    l2.append([a,b])
if (n!=m):
    print('NO')
    
else:
    for i in range(n):
        if l1[i][0] in[0,1,-1] and l1[i][1] in[0,1,-1]:
            if(l2[i][0]) not in [0,-1,1] and (l2[i][1]) not in [0,1,-1]:
                print('YES')
            else:
                print('NO')

    

