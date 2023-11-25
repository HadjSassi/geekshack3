n=int(input())
ch= input()
def getFactors(n):
    factors=[];
    for i in range(1, n + 1):
        if n % i == 0:
            factors.append(i)
    return factors
def reverse(input):
    if len(input) <= 1:
        return input
 
    return reverse(input[1:]) + input[0]    
L1=getFactors(n)
L2=getFactors(n).reverse
if ch[0]=="D":
    s=ch[2:]
    for i in range (len(L1)):
        ch=reverse(s[0:L1[i]])
        for j in range (0,L1[i]):
            s=ch+s[L1[i]:]
            
            
    print(s)
if ch[0]=="E":

    s=ch[2:]
    for i in range (len(L1)):
        ch=reverse(s[0:L2[i]+1])
        for j in range (0,L2[i]):
            s=ch+s[L2[i]:]
    print(s)
        
        