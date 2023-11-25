ch=input()
s=1;
test=True
ch1=ch
while(test==True):
    test=False
    for i in range(0,len(ch1)):
        if ch[i::i+2]=="tt":
            print(ch[i::i+2])
            ch="v"+ch[i+2::]
            print(ch)
            test=True
            s=s+1
        elif ch[i::i+2]=="vv":
            ch="t"+ch[i+2::]
            test=True
            s=s+1
print(s)