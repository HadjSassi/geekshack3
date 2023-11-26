n=int(input())
ch=input()
l=ch.split()
t=[]
s=set()
S1=set(l)
for x in l:
    t.append(l.count(x))
    s.add(l.count(x))
t.sort()
if len (s)==1:
    print('0')
else:
    m=0
    for x in S1:
        m+=l.count(x)
    print(m-t[n-1]) 