  
try:
    input()

    Main=input()
    B=input()
    A = (input())


    kifkif=0
    mo5=0
    for l in range(len(B)):
         for k in range(len(Main)):
            if B[l]!=Main[k]:
                 mo5=mo5+1
            elif B[l]==Main[k]:
                kifkif=kifkif+1
                if(mo5==len(B)&(kifkif==0)):
                    print(B[5:]+" : U")
                elif(kifkif==len(B))&(mo5==0):
                    print(B[5:])
                elif (kifkif>0):
                    print(B[5:]+" : U")
            break


        
        

    kifkif=0
    mo5=0
    for i in range(len(A)):
        for j in range(len(Main)):
            if Main[j]!=A[i]:
                mo5=mo5+1
            elif Main[j]==A[i]:
                kidkif=kifkif+1
                if(mo5==len(A) &(kifkif==0)):
                    print(A[5:]+" : U")
                elif(kifkif==len(A)&(mo5==0)):
                    print(A[5:])
                elif (kifkif>0):
                    print(A[5:]+" : M")
        break
               
except :
    print("NO")  
        
 