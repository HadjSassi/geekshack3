s=input()
nb=0
a=0
while "chak" in s:
    a=s.index("chak")
    s=s[(a+4):]
    c=s.count("chouka")
    nb=nb+c
    
print(nb)    
    
    

