d = input()
L= d.split(" ")
dec1=int(L[0])
dec2= int(L[1])
L
for i in range (dec1,dec2+1):
    binaire = ""
    while i > 0:
        binaire = str(i % 2) + binaire
        i //= 2

    print(binaire)