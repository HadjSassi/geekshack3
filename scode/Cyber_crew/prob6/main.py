def reverse(ch):
    l=list(ch)
    ch="".join(l[::-1])
    return ch
n=int(input())
ch1,ch2=map(str,input().split())
if ch1=='E':
    for i in range(2,n//2+1):
        if n % i ==0:
            ch2=reverse(ch2[1:i])
else:
    for i in range((n//2)+1,2,-1):
        if n % i ==0:
            ch2=reverse(ch2[1:i])
print(ch2)
    
