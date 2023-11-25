ch=input()
l=list(ch)
def palindrome(l):
    return (l==l[::-1])
j=-1
nb=0
a=0
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
                
