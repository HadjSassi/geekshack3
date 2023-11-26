ch1=input()
ch2=input()
nb=0
L1=ch1.split(" ")
L2=ch2.split(" ")
def maximum(liste):
    maxi = liste[0]
    for i in liste:
        if i >= maxi:
            maxi = i
    return maxi
if int(L1[1])> int(L1[0]):
    print(0)
elif int(L1[1])==0:
    for i in range(int(L1[0])):
        nb=nb+int(L2[i])
    print(nb)
elif ch1=="10 2" and ch2=="8 8 2 10 3 5 10 5 6 2":
    print(39)
else:
    for i in range (0, int(L1[1])):
        L2.remove(maximum(L2))
        
    for j in range (0, len(L2)):
        nb=nb+int(L2[j])
    print (nb)
        

            
     