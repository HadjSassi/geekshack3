
import math
def pgcd_liste(liste):
    pgcd = liste[0]
    for i in range(1, len(liste)):
        pgcd = math.gcd(pgcd, liste[i])
    return pgcd

n=int(input())
ch=input()
l=ch.split()
n=0
for i in range (len(l)):
    l[i]=int(l[i])
for i in range(len(l)-1):
    n=pgcd_liste(l[:i+1])*l[i]

print(n)
    
       