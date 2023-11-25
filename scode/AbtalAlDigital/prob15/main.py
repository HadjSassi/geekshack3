s,e=map(int,input().split())
count=0
for i in range(s,e+1):
    if str(bin(i)).count("0")==2:
        count+=1
    if str(bin(i))[2]=="0"
        count-=1
print(count)
        
       