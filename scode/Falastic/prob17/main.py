c=input()
s=set()
s.add(c)
for i in range (len(c)):
    d=c
    d=(d[i:]).replace("tt","v")
    s.add(d)
    d=(d[i:]).replace("vv","t")
    s.add(d)
print(len(s)%1000000007)
 