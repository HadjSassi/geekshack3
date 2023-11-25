ch=input()
l=list(ch)
def palindrome(l):
    return (l==l[::-1])
j=-1
a=0
def occurence(l):
    nb=0
    for i in l :
        if l.count(i) ==1 :
            nb+=1
    if nb>1 :
        return(True)
    else :
        return(False)
nb=0
if (occurence(l)==True):
    print("-1")
elif (len(l) % 2==0) and (occurence(l)==False):
    print("-1")
elif (len(l) %2 ==1) and (occurence(l)==True) :
    print("-1")
else:
    
    for i in range(len(ch)):
        if(l[i]!=[j]) :
            while palindrome(l)==False :
                aux=l[j]
                l[j] = l[j-1]
                l[j-1]=aux
                nb+=1
                
                if(l[j]==l[j-1]):
                    
                    break
                elif j==-len(l)+i :
                    
                    break
                else :
                    j=j-1

            
    print(nb)
                

