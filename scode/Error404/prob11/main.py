n,k=map(int,input().split())
ch=input()
l=[]
for i in range(len(ch)):
    l=ch.split(" ")
for i in range(k):
    l.remove(max(l))

s=0
for i in l :
    s=s+int(i)
print(s)
    

