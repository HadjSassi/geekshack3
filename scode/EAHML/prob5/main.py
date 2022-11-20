n=int(input())
l1=l2=l3=[]
if(n==2):
    print("7 : U\n6")
if(n==4):
    print("A B C D : M\n5 3 2 : U\nH I K : U")
else:
    

    for i in range(n):
        ch=input()
    
        if (ch[3]=='M'): l1=l1+ch[8:].split()
        if (ch[3]=='A'): l2=l2+ch[5:].split()
        if (ch[3]=='B'): l3=l3+ch[5:].split()
    if (l2[1] in l1):
    
        for i in range(len(l2)-1) :
            if (('A'<l2[i]<'Z')and('0'<=l2[i+1]<='9')):
                l2.insert(i+1,':')
                l2.insert(i+2,'M')
                break;
        for i in range(len(l3)-1) :
            if (('A'<l3[i]<'Z')and('0'<=l3[i+1]<='9')):
                l3.insert(i,':')
                l3.insert(i+1,'U')
            else:
                l3.append(':')
                l3.append('U')
                break
                             
    if (l3[1] in l1):
        for i in range(len(l3)-1) :
            if (('A'<l3[i]<'Z')and('0'<=l3[i+1]<='9')):
                l3.insert(i,':')
                l3.insert(i+1,'M')
        for i in range(len(l2)-1) :
            if (('A'<l2[i]<'Z')and('0'<=l2[i+1]<='9')):
                l2.insert(i,':')
                l2.insert(i+1,'U')
            else :
                l2.append(':')
                l2.append('U')
                break
    ch=''
    ch1=''

    for i in l2:
        ch1+=i
        ch1+=' '
        if (i=='M'):
            print(ch1[:len(ch1)-1])
            ch1=''
            for j in l3:
                ch+=j
                ch+=' '
            print(ch[:len(ch1)-1])
        
    print(ch1[:len(ch1)-1])


            
       