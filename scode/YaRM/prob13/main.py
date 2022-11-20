class Machine: 
    def __init__(self, indice, cout, gain): 
        self.indice = int(indice)        
        self.cout = int(cout)
        self.gain = int(gain)
    def __lt__(self, other): 
        return self.gain < other.gain
def cal(b,n,l):
    if not l:
        return 0
    if b-l[0].cout>= 0:
            return max(l[0].gain+cal(b-l[0].cout,n-1,l[1::]),0+cal(b,n-1,l[1::]))
    return 0+cal(b,n-1,l[1::])
    
def calcul():
    try:
        ch=input()
        ch=ch.split()
        b=int(ch[0])
        ch=input()
        ch=ch.split()
        n=int(ch[0])
        l=[0]*2*n
        k=-1
        for i in range (n):
            k+=1
            ch=input()
            ch=ch.split()
            m=Machine(i,ch[0],ch[1])
            r=Machine(i,ch[0],ch[1])
            l[k+i]=m
            l[k+i+1]=r
    except:
        print('INPUT_ERROR')
        return
    print(cal(b,2*n,l))
calcul()