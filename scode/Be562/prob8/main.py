try:
    
    ch=input()
    l=ch.split()
    for i in range(len(l)) :
        l[i]=int(l[i])
    l=sorted(l)
    l=l[::-1]
    print(min(l[0],l[1])*min(l[2],l[3]))
except:
    print('NO')