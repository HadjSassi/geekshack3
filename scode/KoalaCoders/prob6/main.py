n=int(input())
c,a=map(str,input().split())
def dev(n) : 
    l=[1]
    for i in range(n) :
        if n%2==0:
            l.append(i)
    l.append(n)
    return l 
l=dev(n)
def mirror(ch):
    ch=a.split('*')
    m=[]
    for i in range(len(ch),-1):
        m=ch[i]
    return '*'.join(m)
def code(a,l) :
    ch=a.split('*')
    for i in range(n) : 
        for j in range(len(l),-1):
            ch[0],ch[j-1]=ch[j-1],ch[0] 
            print(ch)
    return '*'.join(ch) 
def decode(a,l) : 
    ch=a.split('*')
    for i in range(n) : 
        for j in range(len(l)) : 
            ch[0],ch[j-1]=ch[j-1],ch[0] 
            print(ch) 
    return '*'.join(ch)
if c =='D':
    print(code(mirror(a),l) )
if c =='E' :
    print(mirror(decode(a),l))