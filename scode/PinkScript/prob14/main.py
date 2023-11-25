s=input()
nb=0
def valide(s):
    return s==s[::-1]
for i in range (len(s)):
    s[i]=aux
    aux=s[i+1]
    s[i+1]=s[i]
    if valide(s):
       nb =nb+1
nb=-1
print(nb)
       


    
        