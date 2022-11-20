def shortest(Px,Py,Gx,Gy,ob):
    scr=[]
    queue=[]
    p=[[1,0],[0,1],[-1,0],[0,-1],]
    for i in p:
        if abs(Px-Gx+i[0])<=abs(Px-Gx) and ([Px+1,Py] in ob or [Px-1,Py] in ob or abs(Py-Gy+i[1])<=abs(Py-Gy)):
            if Px-Gx+i[0]==0 and Py-Gy+i[1]==0:
                scr.append(1)
            elif [Px+i[0],Py+i[1]] not in ob:
                queue.append([[Px+i[0],Py+i[1]],[[Px,Py]],1])
    #print(queue)
    while(len(queue)!=0):
        x=queue[len(queue)-1][0][0]
        y=queue[len(queue)-1][0][1]
        visited=queue[len(queue)-1][1]
        score=queue[len(queue)-1][2]
        queue.pop()
        for i in p:
            if ([x+1,y] in ob or [x-1,y] in ob or abs(y-Gy+i[1])<=abs(y-Gy)) and ([x,y-1] in ob or [x,y+1] in ob or abs(x-Gx+i[0])<=abs(x-Gx))and [x+i[0],y+i[1]] not in visited and y+i[1] in range(l) and x+i[0] in range(w):
                if x-Gx+i[0]==0 and y-Gy+i[1]==0:
                    scr.append(score+1)
                elif [x+i[0],y+i[1]] not in ob:
                    visited.append([x+i[0],y+i[1]])
                    queue.append([[x+i[0],y+i[1]],visited,score+1])
        #print(queue)
    if len(scr)!=0:
        return min(scr)
    else:
        return 0

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
Dx=int(L[0])
Dy=int(L[1])

s=input()
L=s.split(' ')
if '' in L:
    L.remove('')
nh=int(L[0])
no=int(L[1])
hum=[]
ob1=[]
for i in range(nh):
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    hum.append([int(L[0]),int(L[1])])
for i in range(no):
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    ob1.append([int(L[0]),int(L[1])])
#print(hum)
#print(ob1)
#print(shortest(Dx,Dy,hum[0][0],hum[0][1]))
som=0
for j in range(nh):
    if j==0:
        x1=Dx
        y1=Dy
    H=[shortest(x1,y1,hum[i][0],hum[i][1],ob1) for i in range(len(hum))]
    #print(H.index(min(H)))
    #print(min(H))
    som+=min(H)
    x1=hum[H.index(min(H))][0]
    y1=hum[H.index(min(H))][1]
    #print([x1,y1])
    hum.remove([x1,y1])
    #print(hum)
    if j == nh-1:
        som+=shortest(x1,y1,Dx,Dy,ob1)
print(som)
   