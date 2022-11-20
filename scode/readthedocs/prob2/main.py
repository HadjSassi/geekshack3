N , F , T , A = input().strip().split(" ")
N = int(N)
F = int(F)
T = int(T)
A = int(A)
L = []
BS = []
for i in range(N): 
    
    
    Di , Ci , Dr , Cr = input().strip().split(" ")
    Di = int(Di)
    Ci = int(Ci)
    Dr = int(Dr)
    Cr = int(Ci)
    L.append([Di,Ci,Dr,Cr])


for i in range(A) : 
    
    nbi , pi , nbr , pr = input().strip().split(" ")
    nbi = int(nbi)
    pi = int(pi)
    nbr = int(nbr)
    pr = int(pr)
    BS.append([nbi,pi,nbr,pr])


k = 0
G = 0
for k in range(len(L)):
    G += (F - T - L[k][0] )*L[k][1] + (F-L[k][2])*L[k][3]
    
     
G += ((F-L[-1][2])*L[-1][3]) + L[1][1]*2
# + (F-(F-L[-1][2]))*L[-1][3]


P = 0 

for j in range(len(BS)): 
    P += BS[j][0]*BS[j][1] + BS[j][2] * BS[j][3]
      


print(G)
print(P)
print(P - G)   