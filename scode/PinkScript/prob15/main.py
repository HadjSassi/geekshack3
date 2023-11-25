d = input()
dec=int(d)
binaire = ""
while dec > 0:
    binaire = str(dec % 2) + binaire
    dec //= 2

print("Le nombre en binaire est :", binaire)