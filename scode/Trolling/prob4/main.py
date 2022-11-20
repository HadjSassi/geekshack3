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
        #print(L)
        for j in range(len(L)):
            if L[j]=='S':
                mp[i+1][j+1]=1
            elif L[j]=='T':
                mp[i+1][j+1]=2
    #print(mp)
    passed=[]
    ar=[[1,0],[-1,0],[0,1],[0,-1]]
    scr_s=[]
    scr_t=[]
    queue=[]
    for i in range(1,n+1):
        for j in range(1,9):
            cnt=0
            if mp[i][j] in [1,2] and [i,j] not in passed:
                d=mp[i][j]
                passed.append([i,j])
                cnt=1
                x=i
                y=j
                for k in ar:
                    if mp[x+k[0]][y+k[1]]==d and [x+k[0],y+k[1]] not in passed:
                        cnt+=1
                        passed.append([x+k[0],y+k[1]])
                        queue.append([x+k[0],y+k[1]])
                while len(queue)!=0:
                    x=queue[len(queue)-1][0]
                    y=queue[len(queue)-1][1]
                    queue.remove([x,y])
                    for k in ar:
                        if mp[x+k[0]][y+k[1]]==d and [x+k[0],y+k[1]] not in passed:
                            passed.append([x+k[0],y+k[1]])
                            cnt+=1
                            queue.append([x+k[0],y+k[1]])
                if d==1:
                    scr_s.append(cnt*100)
                else:
                    scr_t.append(cnt*100)
    scr_s.sort()
    scr_t.sort()
    print('S',end=(' '))
    for i in range(len(scr_s)):
        if i!=len(scr_s)-1:
            print(scr_s[i],end=(' '))
        else:
            print(scr_s[i])
    print('T',end=(' '))
    for i in range(len(scr_t)):
        if i!=len(scr_t)-1:
            print(scr_t[i],end=(' '))
        else:
            print(scr_t[i])
    break
