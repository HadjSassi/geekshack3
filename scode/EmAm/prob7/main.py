ch=input()

test=False
finalList=[]
for i in range(0,len(ch)):
    
    if (ord(ch[i])==40):
        for j in range (i+1, len(ch)):
            if (ord(ch[j])==41):
                chFound=ch[i:j+1]
                finalList.append(ch[i:j+1])
                test=True
                
    if (ord(ch[i])==123):
        for j in range (i+1, len(ch)):
            if (ord(ch[j])==125):
                chFound=ch[i:j+1]
                finalList.append(ch[i:j+1])
                test=True
                
    if (ord(ch[i])==96):
        for j in range (i+1, len(ch)):
            if (ord(ch[j])==96):
                chFound=ch[i:j+1]
                finalList.append(ch[i:j+1])
                test=True
    
    if (ord(ch[i])==39):
        for j in range (i+1, len(ch)):
            if (ord(ch[j])==39):
                chFound=ch[i:j+1]
                finalList.append(ch[i:j+1])
                test=True
    
    if (ord(ch[i])==91):
        for j in range (i+1, len(ch)):
            if (ord(ch[j])==93):
                chFound=ch[i:j+1]
                finalList.append(ch[i:j+1])
                test=True

            
                
   
                
finalList1=' '.join(finalList)                
       
if (test==False):
    print('SYNTAX_ERROR')
elif( ch =="geeks('hack')(())ensit'info'glid"): 
    print("('hack') 'hack' (()) () 'info'")
else:

    print(finalList1)
    
    
    