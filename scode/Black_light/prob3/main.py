s=input()
l=s.split()
s=''.join(l)
i=s.find("chak")
c=0
while(i>-1):
    c+=s[i:].count("chouka")
    i=s[i+4:].find("chak")
print(c)

       