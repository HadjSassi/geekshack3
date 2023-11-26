ch=input()
for i in range (int(ch[0])):
    for j in range (int(ch[1])):
        if ch.count(1)==3:
            print(1)
        elif ch.count(2)==3:
            print(2)
        else:
            print(0)