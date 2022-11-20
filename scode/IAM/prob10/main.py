nbU=int(input())
s=0

for i in range(nbU):
    ch =input()
    l=ch.split(" ")
    sh=""
    l1=input().split(" ")
    if(l[1].isalpha()):
        break
    else:
        for j in range(len(l1)-1):
            if(int(l1[j+1])-int(l1[j]))<int(l[1]):
                s+=abs(int(l1[j])-int(l1[j+1]))
            else:
                s+=int(l[1])
        s+=int(l[1])
if(not l[1].isalpha()):        
    print(s)
else:
    print("NO")