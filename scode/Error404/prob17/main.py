def fact(n):
    s=1
    for i in range(1,n+1):
        s=s*i
    return(s)
def comb(n,p):
    return(fact(n)/((fact(n-p))*fact(p)))
nb=0;
ch=input()
k=1

    
while (k<len(ch)):
    
    if (ch[k]==ch[k-1]) :
        nb+=1
        k=k+1
    k=k+1
        
    
x=comb(len(ch),nb)

x=int(x%1000000007)
if (len(ch)<=4):
    print(x)
else :
    print(x-4)
    
