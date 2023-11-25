n=int(input())
c,a=map(str,input().split())
def dev(n) :
    l=[]
    for i in range(1,n) :
        if n%i==0:
            l.append(i)
    l.append(n)
    return l
l=dev(n)
def code(a,l) :
  for d in range(len(l)-1,0,-1):
      ch2=a[:l[d]]
      a=ch2[::-1]+a[l[d]::]
  return a
def decode(a,l) :
    for d in l:
        ch2 = a[:d]
        a = ch2[::-1] + a[d::]
    return a
if c =='E':
    print(code(a,l) )
if c =='D' :
    print(decode(a,l))
