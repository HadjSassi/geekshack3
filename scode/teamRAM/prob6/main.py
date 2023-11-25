def reverses(string):
    string = string[::-1]
    return string


def sub_slice(ch,d):
    ch1=""
    for i in range(d):
        ch1=ch1+ch[i]
    ch1=reverses(ch1)
    for j in range(d,len(ch)):
        ch1=ch1+ch[j]
    return(ch1)
    
    
def est_diviseur(n,i):
    if (n%i==0):
        return 1
    else:
        return 0

n=int(input(""))
c,A = input("").split()
ch1=""
ch2=""
a = []
for i in range(n,0,-1):
    if n%i==0:
        a.append(i)
if (c=="E"):
    for j in range(len(a)):
        A=sub_slice(A,a[j])
    print(A)
if (c=="D"):
    for x in range(len(a)-1,-1,-1):
        A=sub_slice(A,a[x])
    print(A)