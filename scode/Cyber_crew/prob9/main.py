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
    
if n==m:
    ch=''
    for i in range(n):
        if l1[i][0] in[0,1,-1] and l1[i][1] in[0,1,-1]:
            if(l2[i][0])!=0 and (l2[i][1])  !=0:
                ch='YES'
    if(ch==''):
        print('NO')
    else:
        print(ch)
        

    

   