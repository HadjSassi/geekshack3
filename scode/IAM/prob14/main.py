ch=input()
l=ch.split(" ")
ts=int(input())
tn=input()
if (tn.isalpha()):
    print("INPUT_ERROR")
else:
    tn=int(tn)
    x=int(l[0])*int(l[1])-tn*ts**2
    if(x==0)or(x==int(l[0])*int(l[1])):
        print(0)
