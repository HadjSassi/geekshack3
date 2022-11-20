n=int (input())
l=[]
for i in range(n):
    ch=input()
    l.append(ch)
for e in l:
    s=0
    for i in range(len(e)//2):
        if (e[i] !=e[len(e)-i-1]):
            s+=abs(ord(e[i])-ord(e[len(e)-i-1]))
    print(s) 