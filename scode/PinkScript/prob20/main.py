ch=input()
L=[[]]
for i in range (int(ch[0])):
    c=input()
    L[i]=c.split(" ")
for i in range (int(ch[0])):
    for j in range (int(ch[1])):
        if L[i].count(1)==3:
            print(1)
        elif L[i].count(2)==3:
            print(2)
        else:
            print(0)