while 1:
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    w=int(L[0])
    l=int(L[1])
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    Gx=int(L[0])
    Gy=int(L[1])
    Px=int(L[2])
    Py=int(L[3])
    n=int(input())
    ob=[]
    queue=[]
    check=True
    for i in range(n):
        s=input()
        L=s.split(' ')
        if '' in L:
            L.remove('')
        if L[0].isnumeric():
            ob.append([int(L[0]),int(L[1])])
        else:
            check=False
    if not check:
        print('INPUT_ERROR')
        break
    scr=[]
    p=[[1,0],[1,1],[0,1],[-1,1],[-1,0],[-1,-1],[0,-1],[1,-1]]
    for i in p:
        if abs(Px-Gx+i[0])<=abs(Px-Gx) and abs(Py-Gy+i[1])<=abs(Py-Gy):
            if Px-Gx+i[0]==0 and Py-Gy+i[1]==0:
                scr.append(1)
            elif [Px+i[0],Py+i[1]] not in ob:
                queue.append([[Px+i[0],Py+i[1]],[[Px,Py]],1])
    while(len(queue)!=0):
        x=queue[len(queue)-1][0][0]
        y=queue[len(queue)-1][0][1]
        visited=queue[len(queue)-1][1]
        score=queue[len(queue)-1][2]
        queue.pop()
        for i in p:
            if abs(y-Gy+i[1])<=abs(y-Gy) and ([x,y-1] in ob or [x,y+1] in ob or abs(x-Gx+i[0])<=abs(x-Gx))and [x+i[0],y+i[1]] not in visited and y+i[1] in range(l) and x+i[0] in range(w):
                if x-Gx+i[0]==0 and y-Gy+i[1]==0:
                    scr.append(score+1)
                elif [x+i[0],y+i[1]] not in ob:
                    visited.append([x+i[0],y+i[1]])
                    queue.append([[x+i[0],y+i[1]],visited,score+1])
    if len(scr)!=0:
        print(min(scr))
    else:
        print(0)
    break
 