l = [int(x) for x in input().split()]

nb=0
for i in range(l[0],l[1]) :
  ch=bin(i)
  if (ch[2:].count("0")==1):
     nb=nb+1
     print(nb)
  