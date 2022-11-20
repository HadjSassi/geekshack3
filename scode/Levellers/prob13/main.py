B=int(input())
N=int(input())
machine=[]

Mat=[
    [0,1,2],
    [0,2,1],
    [1,2,0],
    [1,0,2],
    [2,0,1],
    [2,1,0],
    [2,0,0],
    [0,2,0],
    [0,0,2],
    [1,0,0],
    [0,1,0],
    [0,0,1],
    [1,1,0],
    [0,1,1],
    [1,0,1],
    [2,2,0],
    [0,2,2],
    [2,0,2],
    ]

def sum(L,machine):
    s=0;
    for i in range(len(L)):
        s+=L[i]*int(machine[i][0])
    return s
    
def efficiency(L,machine):
    s=0;
    for i in range(len(L)):
        s+=L[i]*int(machine[i][1])
    return s
        
        

for i in range(N):
    machine.append(input().split(" "))
 
R=[]  
for x in Mat:
    if(sum(x,machine)<=B) :
        R.append(efficiency(x,machine))
        
print(max(R))

    
    
     
