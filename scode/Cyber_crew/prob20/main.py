n,m=map(int,input().split())
t=[]
l2=[2,2,2,2]
l1=[1,1,1,1]
for i in range(n):
    ch=input()
    t.append(ch.split())

for i in range(n):
    for j in range(m-5):
        if (t[i][j:j+5]==l2):
            print('2')
        elif (t[i][j:j+5]==l1):
            print('1')
        else:
            c=[]
            for k in range(i+3,i):
                c.append((t[k][j]))
          
            if (c[:2]==[0,0]):
                print('2')
            
           
       
        

    

  