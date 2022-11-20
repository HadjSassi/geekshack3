
ch=input()
list_open=['(',"'",'"','{','[']
list_close=[')',"'",'"','}',']']
i=-1
while (i <len(ch)):
    i+=1
    if(ch[i] in list_open):
       pos1=list_open.index(ch[i])
       j=i+1
       while(j<len(ch)):
           if(ch[j]==list_close[pos1]):
               print(list_close[pos1])
               
               break
           j=j+1
       if(j==len(ch)) : 
               print( 'SYNTAX_ERROR')
               break
    
           
           
     