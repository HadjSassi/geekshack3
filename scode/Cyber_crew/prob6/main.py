def reverse(ch):
    l=list(ch)
    ch="".join(l[::-1])
    return ch
def permutation1(l,d,y):
    i=y
    j=i+d-1
    while(i<j):
        x=l[i]
        l[i]=l[j]
        l[j]=x
        i+=1
        j-=1
    return(l)

n=int(input())
ch1,ch2=map(str,input().split())
l=list(reverse(ch2))
if ch2=='':
    pass
elif ch1=='E':
    for i in range((n//2),1,-1):
       if n % i ==0:
           l=permutation1(l,i,0)
else:
    for i in range((n//2),1,-1):
        if n % i ==0:
            l=permutation1(l,i,n//2)
ch2=''.join(l)
print(ch2)
    
        