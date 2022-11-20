try :
    s = input()
    n=int(s)
    l=[]
    for i in range(n):
      l1=input().split(" ")
      
      l.append(l1)

    main=[x for x in l if x[1]=="Main"]
    A = [x for x in l if x[1]=="A"]
    B = [x for x in l if x[1]=="B"]
    M=[]
    U=[]
    N=[]
    for i in A:
     if (i[-1]==""):    
       i.pop(-1)
    for i in A:
        t=True
        for j in main:
          if (i[2:]==j[2:]):
             N.append(i[2:])
             break
          else:
              for k in j[2:]:
                  for l in i[2:]:
                      if (k==l):
                          t=False
                          break
                  if(t==True):
                      break;
                
        if(t and (i[2:] not in N)):
                  U.append(i[2:])
        else:
 
            if (i[2:] not in N):
                  M.append(i[2:])

    A=B
    for i in A:
     if (i[-1]==""):
       i.pop(-1)
    for i in A:
        t=True
        for j in main:
          if (i[2:]==j[2:]):
             N.append(i[2:])
             break
          else:
              for k in j[2:]:
                  for l in i[2:]:
                      if (k==l):
                          t=False
                          break
                  if(t==True):
                      break;
                
        if(t and (i[2:] not in N)):
                  U.append(i[2:])
        else:
 
            if (i[2:] not in N):
                  M.append(i[2:])
    for i in M:
        for j in i:
         print(j,end=' ')
        print(": M")
    O=M
    M=U
    #print(M)
    for i in M:
      for j in i:
         print(j,end=' ')
      print(": U")
    M=N
    for i in M:
        for j in i:
            if (j==i[-1]):
                print(j)
            else:
                print(j,end=' ')
        #print("")
    D=[]
    for i in main :
        if (i[2:] not in N) :
            D.append(i)
    for i in D :
        test =False
        for p in O :
            if (i[2] ==p[0]):
                test =True
                break
        if ((test ==False) and (i not in O)):
            for j in i[2:]:
             if (j==i[-1]):
                print(j)
             else:
                print(j,end=' ')
                
except EOFError :
    print ("NO") 