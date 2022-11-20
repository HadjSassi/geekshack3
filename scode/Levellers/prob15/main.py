n = int(input())

Specials=[ [['1','2'], 
            ['4','3']],
            
           [['4','1'], 
            ['3','2']],
            
           [['3','4'], 
            ['2','1']],
            
           [['2','3'], 
           ['1','4']],
           
           [['1','4'], 
           ['2','3']],
           
           [['4','3'], 
           ['1','2']],
           
           [['3','2'], 
            ['4','1']],
            
           [['2','1'], 
            ['3','4']]
         ]
Mat=[]
for i in range (0,n) :
    ch=input()
    Mat.append(ch.split())



s=0;
for j in range(len(Mat)-1):
    for i in range(len(Mat[0])-1):
       X = [row[0+i:2+i] for row in Mat[0+j:2+j]]
       
       if(X in Specials):
           s+=1

print (s)  