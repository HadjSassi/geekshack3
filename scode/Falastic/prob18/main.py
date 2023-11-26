n=int(input())
while True:    
    c=input()
    if(len(c)==n):
        break
co=counter(c)
cpx=0
i=1
while(i<len(c)):
    while(c[i]==c[i-1]):
        i+=1
    if(co(c[i-1]!=i)):
       c=c.replace(c[i],c[i-1])
       cpx+=co(c[i])
       co=counter(c)
print(cpx)
