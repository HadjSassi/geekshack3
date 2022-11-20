lw=input()
Llw=lw.split(' ')
Ts=input()
Tn=input()
P=[]
for i in Llw:
    P.append(i)
P.append(Ts) 
P.append(Tn)
for j in P:
    if j not in ['0','1','2','3','4','5','6','7','9','8','10','11']:
        print("INPUT_ERROR")
        break
    else :
        L=int(Llw[0])
        W=int(Llw[1])




Tsize=int(Ts)*int(Ts)

if int(Tn)==0:
   print(0)
else : 
    print(((L*W)%int(Ts))*int(Tn)+1)