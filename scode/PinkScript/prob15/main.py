d = input()
L= d.split(" ")
dec1=int(L[0])
dec2= int(L[1])
L1=[]
nb=0
for i in range (dec1,dec2+1):
    binaire = ""
    while i > 0:
        binaire = str(i % 2) + binaire
        i //= 2

    L1.append(binaire)
for i in range (len(L1)):
    if L1[i].count("0")==1:
        nb=nb+1
    
print (nb)   