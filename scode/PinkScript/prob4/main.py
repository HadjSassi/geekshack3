ch=input()
x=""
y=""
l=list(ch)
if l[2]==0 and (int(l[6]) mod 2==0):
    y=str(l[1])
elif l[3]==0:
    x=str(l[0])
print (x+y)