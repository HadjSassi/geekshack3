ch = input()
l = ch.split(" ")

n = int(l[0])
z = int(l[1])

star_1 = []
star_2 = []

for i in range(n):
    ch = input()
    l = ch.split(" ")
    star_1.append(int(l[0]))
    star_2.append(int(l[1]))
star_1.sort()
star_2.sort()

m = 0
while (z > 0):
   
    if len(star_2)==0  :
        for i in range(z):
            m = m + star_1.pop(0)
        break 
    elif z==1:
        if star_1[0] > star_2 [0] :
            m = m + star_2.pop(0)
        else :
            m = m + star_1.pop(0)
    elif len(star_1)==0:
        for i in range(int(z/2)):
            m = m + star_2.pop(0)
        break
    elif len(star_1) > 1:
        if star_2[0] > star_1[0]+star_1[1]:
            z = z-2
            m = m + (star_1.pop(0) + star_1.pop(0))
           
        else :
            z = z-2
            m = m + star_2.pop(0)
            
    else :
        if star_2[0] > star_1[0]:
            z = z-1
            m = m + star_1.pop(0)
            
        else :
            z = z-2
            m = m + star_2.pop(0)
            
print(m) 