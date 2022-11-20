x=input()
n=input()
l=x.split(" ")
m=n.split(" ")
s=0
for i in range (len(m)):
    if m[i]<l[1]:
        s=int(m[i])+4

    else :
        if len(m)==2:
            s=int(l[1])+4
        else:
            s=int(l[1])+int(m[i])
print(s)