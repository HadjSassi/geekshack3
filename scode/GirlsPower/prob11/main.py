n=input()
p=n.split()
c=len(p)
if n.isnumeric== False :
    print("NOT_CLEAR")
if c> 4:
    print("declare-your-position")
if int(p[c-2]) not in [0,1]:
     print("need-backup")
 if int(p[c-1]) not in [0,1]:
     print("run")  
  if int(p[c-1]) != 0:
     print("run")   
     
         
     
     
     

    
       
   
    
    