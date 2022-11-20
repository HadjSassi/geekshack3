ch=input()
ch1=""
i=0
l=["'",'"',"(",")","[","]","{","}"]
p=-1
if (('(' in ch and ')'in ch) or( ch.count("\"")>=2) or 
('[' in ch and ']'in ch ) or ('{' in ch and '}'in ch) or (ch.count("'")>=2) ):
    while (i<len(ch)):
        if (ch[i]=="'" or ch[i]=='"'):
            if(ch[i+1:].find(ch[i])!=-1):
                ch1+=ch[i:ch[i+1:].find(ch[i])+1]+" "
                i+=1
        else:   
            if (ch[i+1:].find(l[l.index(ch[i])+1])!=-1):
                ch1 +=ch[i:ch[i+1:].find(l[l.index(ch[i])+1])+1]+" "
                i+=1
                         
                
    
else:
    print("SYNTAX_ERROR")
      