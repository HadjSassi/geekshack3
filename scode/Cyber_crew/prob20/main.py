
n,m=map(int,input().split())
t=[]
for i in range(n):
    ch=input()
    t.append(ch.split())
j=0
nb=0
for i in t:
    while(j<len(i)-1):
        if i[j]==i[j+1]:
            nb+=1
    if nb==4 :
        print(i[j])
    j=j+1
t1=[]
for i in range(n):
    s=[]
    for j in range(m):
        s.append(t[j][i])
    t1.append(s) 
for i in t1:
    while(j<len(i)-1):
        if i[j]==i[j+1]:
            nb+=1
    if nb>=4 :
        print(i[j])
    j=j+1
for i in range(n-1):
    while(j<m-1):
        if t[i][j]==t[i+1][j+1]:
               nb+=1
        if nb>=4 :
            print(t[i][j])
        j=j+1

        
        
    

        
        
        
        
        
    
    

  