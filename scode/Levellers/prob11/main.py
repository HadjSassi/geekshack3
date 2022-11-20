

#def conversion(n,ch):
    #if (n > 1):
        #ch=ch+str(int(conversion(n // 2))%2)
        
def conversion(n):
   ch=""
   while(n > 0):
      n1=n%2
      ch=str(n1)+ch
      n=n//2
   return ch 
    
    
data =input()



if(data.isalpha()):
    print("NOT_CLEAR")

elif(" " in data):

    x=data.split(" ")
    ch1=""
    for i in x :
        ch=conversion(int(i))
        i= int(ch)
        
        
        if(i ==1) :
            if(ch1!="") :ch1+=" "
            ch1+="take_position"
        elif (i ==10) :
            if(ch1!="") :ch1+=" "
            ch1+="run"
        elif (i ==100) :
            
            if(ch1!="") :ch1+=" "
            ch1+="need_backup"
        elif (i ==1000) :
            if(ch1!="") :ch1+=" "
            ch1+="declare_your_position"
    print(ch1)
        
        
    
else:
   ch=conversion(int(data))
   data= int(ch)
  
   
   if(data ==1) :print("take_position")
   elif (data ==10) :print("run")
   elif (data ==100) :print("need_backup")
   elif (data ==1000) :print("declare_your_position")
   else :
       
       ch=""
       a=(data//1000)*1000
       b=((data%1000)//100)*100
       c=((data%100)//10)*10
       d=data%10
       
       if (a ==1000) :
           if(ch!="") :ch+=" "
           ch=ch+"declare_your_position"
       if (b ==100) :
           if(ch!="") :ch+=" "
           ch=ch+"need_backup"
       if (c ==10) :
           if(ch!="") :ch+=" "
           ch=ch+"run"
       if(d ==1) :
           if(ch!="") :ch+=" "
           ch=ch+"take_position"
       
       print(ch)
       
       
   
   






#if(conversion(data)!=1 or conversion(data)!=10 or conversion(data)!=100 or conversion(data)!=1000):
#    