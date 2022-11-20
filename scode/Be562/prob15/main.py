x=int(input())
l=[]
nb=0
for i in range(x):
    ch=input()
    l1=ch.split()
    l.append(l1)
test=["1","2","3","4"]
for i in range (x-1):
    for j in range (len(l[1])-1):
        if (l[i][j] in test):
            p=test.index(l[i][j])
            if (l[i][j+1]==test[(p+1)%4]) and (l[i+1][j+1]==test[(p+2)%4]) and (l[i+1][j]==test[(p+3)%4]):
                nb+=1
            elif (l[i+1][j]==test[(p+1)%4]) and (l[i+1][j+1]==test[(p+2)%4]) and (l[i][j+1]==test[(p+3)%4]):
                nb+=1

print (nb)