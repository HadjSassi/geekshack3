
ch = input()
l = ch.split(' ')
try: 
 l=[int(i) for i in l]

 if len(l)!=4 :
    print('NO')
 else:
    l.sort()
    #print (l)
    m1=l[0]   
    m2=l[1]
    m3=l[2]
    air=m3*m1
    print(air)
except : print('NO')



    
    
    
