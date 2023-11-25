n=input()
B=0
M=0
if n=="1":
    ch=input()
    b=int(ch[0])
    L=ch.split(" ")
    for i in range (1,b+1):
        B=B+int(L[i])
        M=M+int(L[-i])
print (B,M)
        
    
    


        