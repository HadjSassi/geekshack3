n=int(input())
k=int(input())
liste=[]
for i in range(0,n):
    ab=int(input())
    liste.append(ab)
def maxi(liste):
    maxim=0
    for i in liste:
        if (i>maxim):
            maxim=i
    liste.remove(maxim)
    return liste
while (k>=1):
    liste=maxi(liste)
    k-=1
if((len(liste))!=0):
    print(sum(liste))
else:
    print(0)
