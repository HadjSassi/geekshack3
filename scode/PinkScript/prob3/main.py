s=input()
nb=0
a="chakchouka"
b="chak"
c="chouka"


if a in s :
    nb=nb+1
    s.replace(a,"")
elif b in s :
    nb=nb+1
    s.replace(b,"")
        
elif c in s :
    nb=nb+1
    s.replace(c,"")
        
print (nb) 