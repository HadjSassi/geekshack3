chi=input()
l=[]

def f1(ch):
    i=0
    
    while i!=len(ch):
        if ch[i]=='(':
            
            ch1=""
            
            try:
             while ch[i]!=')':
                
                
                ch1+=ch[i]
                i+=1
            except:break
            ch1+=ch[i]
            if ch1 not in l:
              l.append(ch1)
            
        i+=1
def f2(ch):
    i=0
    
    while i!=len(ch):
        if ch[i]=='{':
            
            ch1=""
            while ch[i]!='}':
                
                ch1+=ch[i]
                i+=1
                
            ch1+=ch[i]
            if ch1 not in l:
              l.append(ch1)
            
        i+=1
def f3(ch):
    i=0
    
    while i!=len(ch):
        if ch[i]=='[':
            
            ch1=""
            while ch[i]!=']':
                
                ch1+=ch[i]
                i+=1
                
            ch1+=ch[i]
            if ch1 not in l:
              l.append(ch1)
            
        i+=1
def f4(ch):
    i=0
    
    while i!=len(ch):
        if ch[i]=="'":
            
            ch1=ch[i]
            i+=1
            try:
             while (ch[i]!="'") :
                
              
               ch1+=ch[i]
               i+=1
            
            except:break    
            ch1+=ch[i]
            if ch1 not in l:
              l.append(ch1)
            
        i+=1
f1(chi)
f2(chi)
f3(chi)
f4(chi)

if l==[]:print('SYNTAX_ERROR')
else:
    print(' '.join(l))
        
     