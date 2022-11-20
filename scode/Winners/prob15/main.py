def tourne(p):
    if p==['1','2','3','4']:
        return True
    if p==['2','3','4','1']:
        return True
    if p==['3','4','1','2']:
        return True
    if p==['4','1','2','3']:
        return True
    if p==['4','3','2','1']:
        return True
    if p==['3','2','1','4']:
        return True
    if p==['2','1','4','3']:
        return True
    if p==['1','4','3','2']:
        return True
    return False
n=int(input())
l=[]
for i in range(n):
    x=input()
    x = x.replace("\r","")
    if x[len(x)-1] == " ":
        x = x[:len(x)-1]
    l.append(x.split(" "))
q=[]
l
s=0
for i in range(n-1):
    m = len(l[i])
    for j in range(m-1):
        q.append(l[i][j])
        q.append(l[i][j+1])
        q.append(l[i+1][j+1])
        q.append(l[i+1][j])
        if tourne(q):
            s+=1
        q=[]
print(s) 