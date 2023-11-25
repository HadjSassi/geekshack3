def lastMove():
    ch1=input()
    ch2=input()
    ch3=input()
    
    def between(c1,c2,c3):
      if  (c1[2]<c2[2]<c3[2]) or(c1[2]>c2[2]>c3[2]) :
               return True
      if  (c1[1]<c2[1]<c3[1]) or(c1[1]>c2[1]>c3[1]) :
                return True
      return False
    if((ch1[2]==ch3[2]==ch2[2]) ) and between(ch1,ch2,ch3):
     return ('NO')  
    if((ch1[1]==ch3[1]==ch2[1]) ) and between(ch1,ch2,ch3):
     return('NO')
    return('YES')
print(lastMove())
                 
     
           
        
