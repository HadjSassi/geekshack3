a = input()
if (len(a)<=5):
    print("NO")
else:
    l=a.split(" ")
    l[0]=int(l[0])
    l[1]=int(l[1])
    l[2]=int(l[2])
    l[3]=int(l[3])
    l.sort()
    print(min(l[0],l[1])*min(l[2],l[3]))
    