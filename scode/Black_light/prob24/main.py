
l=[int(i) for i in input().split()]
iA=0
iB=0
i=0
while i<l[0]:
    i+=1
    iA+=1
    iB+=1
    if l[2]==iA:
        l[1]+=1
        iA=0
    if l[-1]==iB:
        l[-2]+=1
        iB=0
    if l[-2]==l[1] and iA==iB :
        break
print(i)