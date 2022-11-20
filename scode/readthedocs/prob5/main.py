

def RL():
    M = []
    B = []
    
    for k in range(a): 
        x = input()
        if 'Main' in x : 
            M.append(x[8:]) 
            
        else : 
            B.append(x[5:])
    
        
       
                    
    for i in range(len(M)):
        for k in range(len(B)): 
            if M[i] != B[k] : 
                M.append(B[k]+' : U')
            elif M[i][0] == B[k][0]: 
                M[i] = B[k] + " : M" 
            
            
                
            
               
                
               
    # f = 0 
    # for i in range(len(M)): 
    #     for k in range(len(B)): 
    #         if B[k] == M[i] : 
    #             f += 1          
    # if f <  1 : 
    #     M.append(B[k]+': U')
                
    
    for i in range(len(M)):
        print(M[i])
try :
    a = (input())
    if a == '': 
        print('NO')

except EOFError as e:
    print('NO')
    
else :
    a = int(a)
    RL()    
       
         