def nb():
    try:
        ch=input()
        ch=ch.split()
        n = int(ch[0])
        res = []
        main = []
        A= []
        B=[]    
        for i in range (n): 
            ch= input()
            ch2=ch
            ch= ch.split(" ",2)
            if (ch[1]=="Main"):
                try:
                    main.append(ch[2])
                except :
                    res.extend(A)
                    
            if (ch[1]=="A"):
               A.append(ch[2])
            if(ch[1]=="B"):
               B.append(ch[2])
           
                
                
            for i in range(len(main)):
                for j in range (len(A)):
                        if(main[i][0] in A[j]):
                           if(len(main[i].rstrip())==len(A[j].rstrip())):
                               res.append(A[j].rstrip())
                           else :
                               if(len(main[i].rstrip())<len(A[j].rstrip())):
                                   res.append(A[j].rstrip()+" : M")
                    
                        else :
                            if(A[j].rstrip() not in res):
                                if((A[j].rstrip()+" : M" not in res) and (A[j].rstrip() in res)):
                                    res.append(A[j].rstrip()+" : U")
            
                for k in range (len(B)):
                        if(main[i][0] in B[k]):
                           if(len(main[i].rstrip())==len(B[k].rstrip())):
                               res.append(B[k].rstrip())
                           else :
                               if(len(main[i].rstrip())<len(B[k].rstrip())):
                                   res.append(B[k].rstrip()+" : M")
                    
                        else :
                            if(B[k].rstrip() not in res):
                                if((B[k].rstrip()+" : M" not in res) and (B[k].rstrip() in res)):
                                    res.append(B[k].rstrip()+" : U")
            
            for i in A:
                for j in B: 
                    if (i not in main and i.rstrip() not in res and i.rstrip()+" : M" not in res  ):
                        res.append(i+" : U")
                    if(j not in main and j.rstrip() not in res and j.rstrip()+" : M" not in res   ):
                        res.append(j+" : U")
            
            resultantList=[]
            for i in res :
                if (i not in resultantList):
                    resultantList.append(i)
            
            result = [];
        for i in range(len(resultantList)):
            if(resultantList[i][len(resultantList[i])-1]=="M"):
                result.append(resultantList[i])
        for j in range(len(resultantList)):
            if(resultantList[j][len(resultantList[j])-1]=="U"):
                if(resultantList[j][0].isnumeric()):
                    result.append(resultantList[j])
        for x in range(len(resultantList)):
            if(resultantList[x][len(resultantList[x])-1]=="U"):
                if(resultantList[x][0].isalpha()):
                    result.append(resultantList[x])    
        for k in range(len(resultantList)):
            if(resultantList[k][len(resultantList[k])-1]!="M" and resultantList[k][len(resultantList[k])-1]!="U" ):
                result.append(resultantList[k])  
        for v in range(len(resultantList)):
            resultantList[k][len(resultantList[k])-1]!="U" 
            if(len(resultantList[v][0])>len(resultantList[v][1])):
                 result.append(resultantList[v][0])
            else:
                result.append(resultantList[v][1])
        
        for p in result :  
            print(p.rstrip())
            
    
            
    except:
        print("NO")

           
nb()
        
       