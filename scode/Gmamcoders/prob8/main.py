n=int(input())
s1=0
s2=0
for i in range(n):
    d=int(input())
    s=[]
    for j in range(d):
        s[j]=int(input())
        if j%2==0:
            s1+=s[j]
        else:
            s2+=s[j]
print(s1,s2)        
    