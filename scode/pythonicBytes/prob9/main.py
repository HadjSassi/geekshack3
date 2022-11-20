try:
    n_pouch,secondes = input().split()
    n= input().split()
except:
    print('NO')
    exit(0)
ee=[]
for i in range(len(n)-1):
    ee.append([n[i],n[i+1]])

j=0
s=0
while j<int(n_pouch)-1:
   
    if(int(ee[j][1])-int(ee[j][0])<int(secondes)):
        s+=int(ee[j][1])-int(ee[j][0])

    if(int(ee[j][1])-int(ee[j][0])>int(secondes)):
        s+=int(secondes)
    
    j+=1
s+=int(secondes)
print(s)