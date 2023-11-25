n=int(input())
c,ch=map(str,input().split())
l=[]
for i in range(1,n+1) :
    if( n % i) == 0 :
        l.append(i)

if c=="D" :
    l.pop()
    for i in l:
        ch2=ch[:i]
        ch2=ch2[::-1]
        ch=ch2+ch[i:]
    ch=ch[::-1]
    print(ch)
elif c=="E":         
    for i in l[::-1]:
        ch2=ch[:i]
        ch2=ch2[::-1]
        ch=ch2+ch[i:]
    ch
    print(ch)
