n=int(input()) 
l=[]
for i in range(n):
    ch=input()
    l.append(ch)
for i in l:
    nb=0
    ch=i
    j=0
    while j <(len(ch)):
        if ch[j]==" ":
            ch=ch[0:j]+ch[j+1:]
        j+=1
    for j in range(len(ch)//2):
        if ord(ch[j])<ord(ch[len(ch)-j-1]):
            nb+=ord(ch[len(ch)-j-1])-ord(ch[j])
        elif ord(ch[j])>ord(ch[len(ch)-j-1]):
            nb+=ord(ch[j])-ord(ch[len(ch)-j-1])
    print (nb)
    