while 1:
    try:n=int(input())
    except:
        print("NO")
        break
    main=[]
    for i in range(n):
        s=input()
        L=s.split(" ")
        if '' in L:
            L.remove('')
        if L[1]=='Main':
            if len(L)>2:
                main.append([0,L[2:]])
        else:
            #print(main)
            L1=L[2:]
            #print(L1)
            if(len(main)!=0):
                for i in range(len(main)):
                    if L1!=main[i][1]:
                        for j in range(len(main[i][1])):
                            if main[i][1][j] not in L1:
                                if[2,L1] not in main and [1,L1] not in main and [0,L1] not in main:
                                    main.append([2,L1])
                                break
                        else:
                            main[i]=[1,L1]
            else:
                main.append([2,L1])
    for k in range(len(main)):
        if main[k][0]==1:
            for l in range(len(main[k][1])):
                print(main[k][1][l],end=(" "))
            print(': M')
    for p in range(len(main)):
        if main[p][0]==2:
            for l in range(len(main[p][1])):
                print(main[p][1][l],end=(" "))
            print(': U')
    for m in range(len(main)):
        if main[m][0]==0:
            for l in range(len(main[m][1])):
                if(l!=len(main[m][1])-1):
                    print(main[m][1][l],end=(" "))
                else:
                    print(main[m][1][l])
    break
