


s0=input("")
s1="chak"
s2="chouka"
indice=0
s=0
text=s0

while (indice!=-1):
    indice=text.find(s1)
    if(indice==-1):
        break
    
    text=text[indice+len(s1):len(text)]
    y=text.count(s2)
    
    s=s+y
print(s)
    

 