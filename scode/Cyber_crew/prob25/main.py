N=int(input())
ch=input()
l=list(ch)
d=len(l)//2
for i in range (0,d,2):
    x=l[i]
    l[i]=l[d+i]
    l[d+i]=x
print("".join(l))
