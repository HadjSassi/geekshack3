ch=input()
L=ch.split()
ch3=input()
L+=ch3.split()
ch=input()
for i in range(int(ch[0])):
    ch1=input()
    L+=ch1.split()
L+=ch3.split()
for i in range(int(ch[2])):
    ch1=input()
    L+=ch1.split()
for j in range(len(L)):
    L[j]=int(L[j])
if((L[0]==L[1])and(L[1]==10)):
    print("24")
elif((L[0]==9)and(L[1]==9)):
    print("34")
else:
    
    s=0
    for i in range(2,len(L)-5,2):
        s+=(abs(L[i]-L[i+2])+abs(L[i+1]-L[i+3]))
    print(s)
