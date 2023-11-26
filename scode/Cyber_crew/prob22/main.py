ch=input()
if ch ==ch[::-1]:
    print (ch)
else:
    g=len(ch)-1
    d=0
    l=list(ch)
    while(d<g and d<len(l)-1):
        if l[d]!=l[g]:
            if l[d]==l[d+1]:
                x=l[d+1]
                l[d+1]=l[g]
                l[g]=x
                d+=1
                g-=1
            else:
                l[d]=l[g]
                d+=1
                g-=1
    print(''.join(l))   