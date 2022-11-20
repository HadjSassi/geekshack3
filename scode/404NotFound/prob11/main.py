n= input()
if n=='a':
   print("NOT_CLEAR")
   exit(0)
b= []
while(int(n)>0):
    d=int(n)%2
    b.append(d)
    n=int(n)//2
b.reverse()

    
if b==[1,0,0] :
        print("need_backup")
elif b==[1] :
        print("take_position")        
elif b==[1,0] :
        print("run")  
elif b==[1,0,0,0] :
        print("declare_your_position") 
        
        
        
        
        
        
elif b==[1,0,1,0] :
        print("declare_your_position run")         
elif b==[1,1,0] :
        print("need_backup run")           
elif b==[1,1,1] :
        print("need_backup run take_position")        
 