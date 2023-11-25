def reverse(ch):
    l=list(ch)
    ch="".join(l[::-1])
    return ch
def permutation(ch,d):
    i=1
    while(i<d):
        x=l[i]
        l[i]=l[d]
        l[d]=x
        i+=1
        d-=1
    return(l)
n=int(input())
ch1,ch2=map(str,input().split())
if ch1=='E':
    for i in range(n,0,-1):
        if n % i ==0:
            ch2=reverse(ch2[1:i])
else:
    l=list(reverse(ch2))
    
    for i in range((n//2),0,-1):
        if n % i ==0:
            l=permutation(l,i)
    ch2=''.join(l)
print(ch2)
    
    