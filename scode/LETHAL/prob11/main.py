d={1: 'take_position',
10: 'run',
100: 'need_backup',
1000: 'declare_your_position'}
res=[]
ch=input()
if ch.isalpha():
    print("NOT_CLEAR")
else:
 l=ch.split(" ")

 l1=[int(i) for i in l]

 l2=[bin(i)[2:] for i in l1]

 l3=[int(i) for i in l2]
#print(l3)
 for j in l3:
        y=j
        for k in range(4):
            #print(y,k)
           # print(y//pow(10,3-k))
            if y//pow(10,3-k)==1:
                res.append(d.get(pow(10,3-k)))
                y=y%pow(10,3-k)
                
                if y==0 : 
                    #print(res)
                    
                    break
 print(' '.join(res))
                
                

    
        
    
    
     