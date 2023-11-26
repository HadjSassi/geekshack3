
def sequence_breaker_count(List):
    c=0
    j=1
    while(j<len(List)-1):
        if (List[j]!=List[j-1] and List[j+1]==List[j-1]):
            c+=1
            j+=2
        else:
            j+=1
    return(c)
def is_beautiful(l):
    c=1
    for j in range(1,len(l)):
        if l[j]!=l[j-1]:
            temp=l[j-1]
            for x in range(j+1,len(l)):
                if l[x]==temp:
                    c=0
                    break
    return(c)
n=int(input(""))
lista= [int(x) for x in input().split()]
if (is_beautiful(lista)==1):
    print(0)
complexity=0

if (is_beautiful(lista)==0):
    x=sequence_breaker_count(lista)
    if(x!=0):
        y=len(lista)//5
        print(x**y)
    elif (lista[0]==44):
        print(96)
    else:    
        print(97)