n=int(input())
for i in range(n):
    x=input()
    p=list(x)
    k=len(p)
    a=0
    for j in range(k//2):
        if p[j]!=p[k-j-1]:
            if p[j]<p[k-j-1]:
                while p[j]!=p[k-j-1]:
                    p[k-j-1]=chr(ord(p[k-j-1])-1)
                    a+=1
            else :
                while p[j]!=p[k-j-1]:
                    p[k-j-1]=chr(ord(p[k-j-1])+1)
                    a+=1
    print(a)  