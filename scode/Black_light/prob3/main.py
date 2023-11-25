s=input()
l=s.split()
s=''.join(l)
i=s.find("chak")
c=0
while(len(s)>0):
    if(i>-1):
        c+=s[i:].count("chouka")
        i=s[i+4:].find("chak")
    else:
        break
print(c)

     