s = input()
l=len(s)
res=0
for i in range(l-1):
    if (s[i]=="t") and (s[i+1]=="t"):
        s1=s[0:i-1]+"s"+s[i+2:l]
       
        res=+1
    if (s[i]=="s") and (s[i+1]=="s"):
        s2=s[0:i-1]+"t"+s[i+2:l]
        res=+1
print(res)