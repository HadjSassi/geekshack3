from math import sqrt
def manhattan(a, b):
    return sum(abs(val1-val2) for val1, val2 in zip(a,b))
    
def max():
    try:
        ch=input()
        ch=ch.split()
        l=int(ch[0])
        c=int(ch[1])
        ch=input()
        ch=ch.split()
        xg=int(ch[0])
        yg=int(ch[1])
        xp=int(ch[2])
        yp=int(ch[3])
        ch=input()
        ch=ch.split()
        n=int(ch[0])
        o=[0]*l
        for i in range (n):
            ch=input()
            ch=ch.split()
            k=[0]*2
            k[0]=int(ch[0])
            k[1]=int(ch[1])
            o[i]=k
    except:
        print('INPUT_ERROR')
    if l<3:
        if n!=0:
            print(0)
        else:
            print(1)
    
    if l>3:
        C = [[0]*l for i in range(c)]
        C[xg][yg]=1
        C[xp][yp]=1
        #print(o)
        min =100
        xcur = xg 
        ycur= yg
        for i in range (n):
            C[o[i][0]][o[i][1]]=-1
        A=[xg , yg]
        B=[xp , yp]
        print(manhattan(A,B) )

        
max()  