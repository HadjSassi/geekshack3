x=int(input())

ch=input()

l=[]
l=ch.split(" ")
sum=0
for e in l:
    if(int(e))!=1:
        sum+=int(e)
    
print(sum*2)