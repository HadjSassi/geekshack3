ch =input()
a = 0
l = []
i1 , i2 = 0,0
for i in ch :
    if i == "chak"[i1]:
        i1+=1
        if i1==3:
            l.append("chak")
            i1=0
    else :
        i1 = 0
    if i == "chouka"[i2]:
        i2+=1
        if i2==5:
            l.append("chouka")
            i2=0
    else :
        i2 = 0

for i in range(len(l)):
    if l[i] == "chak":
        for k in range(i,len(l)):
            if l[k] == "chouka":
                a+=1
print(a)