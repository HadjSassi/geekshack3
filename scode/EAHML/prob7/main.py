ch=input()
d=dict()
d['{']='}'
d['\'']='\''
d['\"']='\"'
d['(']=')'
d['[']=']'
ch1=""
def fct(ch):
    L2=list()
    if(len(ch)==0):
        print('SYNTAX_ERROR')
        return L2
    else:
        
        
        while (1):
            while ((len(ch)>1)or(ch[0] not in d.keys())):
                ch=ch.replace(ch[0],"")
            if (ch==""):
                print('SYNTAX_ERROR')
                return L2
            else:
                j=1
                while((ch[j] not in d.values())or(j==len(ch))):
                    j+=1
                if(j==len(ch)):
                    print('SYNTAX_ERROR')
                    return L2
                else:
                    L2.append(ch[0:j+1])
                    ch=ch[j+1:]
            

L=[]         
L=fct(ch)
L1=[]
while 1:
    for i in L:
        while(fct(i)!=[]):
            for j in fct(i):
                L1.append(j)
    if(L==L1):
        break
    else:
        L=L1
ch2=""
for j in L:
    ch2=ch2+j
print(ch2) 