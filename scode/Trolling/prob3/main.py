while 1:
    try:n=int(input())
    except:
        print("NO")
        break
    mp=[[0 for j in range(9)] for i in range(n+2)]
    for i in range(n):
        s=input()
        L=s.split(" ")
        if ' ' in L:
            L.remove(' ')
        L1=[int(l) for l in L]
        for j in range(len(L1)):
            mp[i+1][L1[j]+1]=1
    #print(mp)
    passed=[]
    ar=[[1,0],[-1,0],[0,1],[0,-1]]
    scr=[]
    queue=[]
    for i in range(1,n+1):
        for j in range(1,9):
            cnt=0
            if mp[i][j]==1 and [i,j] not in passed:
                passed.append([i,j])
                cnt=1
                x=i
                y=j
                for k in ar:
                    if mp[x+k[0]][y+k[1]]==1 and [x+k[0],y+k[1]] not in passed:
                        cnt+=1
                        passed.append([x+k[0],y+k[1]])
                        queue.append([x+k[0],y+k[1]])
                while len(queue)!=0:
                    x=queue[len(queue)-1][0]
                    y=queue[len(queue)-1][1]
                    queue.remove([x,y])
                    for k in ar:
                        if mp[x+k[0]][y+k[1]]==1 and [x+k[0],y+k[1]] not in passed:
                            passed.append([x+k[0],y+k[1]])
                            cnt+=1
                            queue.append([x+k[0],y+k[1]])
                scr.append(cnt*100)
    scr.sort()
    for i in range(len(scr)):
        print(scr[i])
    break 