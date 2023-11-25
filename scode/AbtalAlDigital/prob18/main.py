def isb (a):
    l=[]
    if len(a)==1:
        return True
    l.append(a[0])
    for i in range(len(a)-1):
        if a[i]!=a[i+1] and a[i+1] not in l:
            l.append(a[i+1])
        elif a[i+1]in l:
            return False
    return True
c=input()
a=input().split()
if isb(a):
    print(0)

    
        