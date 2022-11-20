try:
    
    t=int(input())
    l=[]
    x=0
    s=0
    for x in range(t):
        l=[]
        x=0
        for i in range (2):
            ch=input()
            l1=ch.split()
            l.append(l1)
        x=int(l[0][0])*int(l[0][1])

        for i in range(int(l[0][0])-1):
            if (int(l[1][i+1])-int(l[1][i]))<int(l[0][1]):
                x-=int(l[0][1])-((int(l[1][i+1])-int(l[1][i]))%int(l[0][1]))
        s=s+x

    print(s)    
except :
    print('NO')
