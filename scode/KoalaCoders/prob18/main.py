
def FONKTION_loula(l):
    c=1
    for j in range(1,len(l)):
        if l[j]!=l[j-1]:
            temp=l[j-1]
            for x in range(j+1,len(l)):
                if l[x]==temp:
                    c=0
                    break
    return(c)
def FONKTION_thenya(List):
    c=0
    j=1
    while(j<len(List)-1):
        if (List[j]!=List[j-1] and List[j+1]==List[j-1]):
            c+=1
            j+=2
        else:
            j+=1
    return(c)
n=int(input(""))
sett= [int(x) for x in input().split()]
if (FONKTION_loula(sett)==1):
    print(0)
complexity=0

if (FONKTION_loula(sett)==0):
    x=FONKTION_thenya(sett)
    if(x!=0):
        y=len(sett)//5
        print(x**y)
   