def poly(c,x):
    l=[]
    d=len(c)
    for i in x:
        
        p=0
        for j in range(d-1):
            p+=int(c[j])*pow(int(i),d-1-j)
        if x=="0":
            p+=int(c[-1])
        else:p+=int(x)*int(c[-1])
        l.append(str(p))
        
    print(" ".join(l))

n=int(input())
for i in range(n):
    c=input().split()
    x=input().split()
    poly(c,x)
    
    