x=input()
l=x.split(" ")
if (len(l)!=4):
    print("NO")
else:
    a=int(l[0])
    b=int(l[1])
    c=int(l[2])
    d=int(l[3])
    p=[a,b,c,d]
    p.sort()
    print(p[0]*p[2]) 