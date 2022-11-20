x=(input())
for i in (x):
    if i not in ['0','1','2','3','4','5','6','7','8','9',' ']:
        print("NOT_CLEAR")
        break
    else:

         A={'1':"take_position" , '10':"run" , '100':"need_backup" , '1000':"declare_your_position" }
         p=int(x)
         ch="" 
         while p!=0 :
             ch+=str(p%2) 
             p=p//2 
         ph=ch[::-1]
         result=""
         x= ph.split("1")
         for i in range(len(x)):
            x [i]='1'+ x[i]
         for i in range(1,len(x)):   
            result=result+A[x[i]]  
         print (result) 