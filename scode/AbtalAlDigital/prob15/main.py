s,e=map(int,input().split())
count=0
for i in range(s,e+1):
    x=str(bin(i))
    a=x.count("0")
    if a==2:
        count+=1
    
print(count)
        
     