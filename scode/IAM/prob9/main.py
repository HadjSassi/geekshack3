ch =input()

l=ch.split(" ")
sh=""
l1=input().split(" ")
s=0
for i in range(len(l1)-1):
    if(int(l1[i+1])-int(l1[i]))<int(l[1]):
        s+=abs(int(l1[i])-int(l1[i+1]))
    else:
        s+=int(l[1])
s+=int(l[1])
print(s)