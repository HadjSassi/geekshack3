u = int(input())

j = 0 
for i in range(u): 
    
    N , T = input().strip().split(" ")
    try : 
        N, T = int(N) , int(T)
    except ValueError as e : 
        print('NO')
    
    a = input()
    t = a.split(" ")
    
    for i in range(len(t)): 
        t[i] = int(t[i])
    
    def calc(): 
        x=0
        for i in range(len(t)-1,-1,-1): 
            if (t[i] -t[0] <= T): 
                x= x+t[i]+T
                break
            else : 
                x= x+T
        
        return x
    
    j=j+calc()

print(j)
  