s = input()
if(len(s)!=0):
    n=int(s)
    l=[]
    for i in range(n):
      l1=input().split(" ")
      #print(l1)
      l.append(l1)

    main=[x for x in l if x[1]=="Main"]
    print(main)
    A = [x for x in l if x[1]=="A"]
    print(A)
    B = [x for x in l if x[1]=="B"]
    print(😎

    M=[]
    U=[]
    N=[]
    for i in A:
        t=True
        for j in main:
          if (i[2:]==j[2:]):
             N.append(i[2:])
          else:
              for k in j[2:]:
                  for l in i[2:]:
                      if (k==l):
                          t=False
                          break
              if(t):
                  U.append(i[2:])
              else:
                  M.append(i[2:])

    A=B
    for i in A:
        for j in main:
          if (i[2:]==j[2:]):
              N.append(i[2:])
          else:
              for k in j[2:]:
                  for l in i[2:]:
                      if (k != l):
                          t = False
                          break
              if (t):
                  N.append(i[2:])
              else:
                  U.append(i[2:])

    for i in M:
        for j in i:
         print(j,end=' ')
        print(": M")
    M=U
    #print(M)
    for i in M:
      for j in i:
         print(j,end=' ')
      print(": U")
    M=N
    for i in M:
        for j in i:
            print(j,end=' ')
        print("")
else :
    print("NO")