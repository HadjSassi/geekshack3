ch=input()
ch1=""
nb=0
nb1=nb2=nb3=0
for i in range(len(ch)):
    if ch[i]=='{':
        for j in range(i+1,len(ch)):
            if ch[j]=='}':
                ch1=ch1+" "+ch[i:j+1]
                break

    elif ch[i]=="'":
        nb=nb+1
        for j in range(i+1,len(ch)):
            if (ch[j]=="'") and (nb%2!=0):
                ch1=ch1+" "+ch[i:j+1]
                break

    elif ch[i]=='"':
        nb1+=1
        for j in range(i+1,len(ch)):
            if ch[j]=='"' and (nb1%2!=0):
                ch1=ch1+" "+ch[i:j+1]
                break

    elif ch[i]=="(":
        for j in range(i+1,len(ch)):
            if ch[j]==")":
                ch1=ch1+" "+ch[i:j+1]
                break

    elif ch[i]=='[':
        for j in range(i+1,len(ch)):
            if ch[j]==']':
                ch1=ch1+" "+ch[i:j+1]
                break

    elif ch[i]=="`":
        for j in range(i+1,len(ch)):
            if ch[j]=="`":
                ch1=ch1+" "+ch[i:j+1]
                break     

if ch1=="":
    ch1='SYNTAX_ERROR'
if ch1[0]==" ":
    ch1=ch1[1:]
print(ch1)
                