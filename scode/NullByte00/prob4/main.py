#while True:
from  math import floor

l, h, x, y, vx, vy, K = map(int, input().split())
colsx=[]
#x time to colide
if K == 0:
    print(x,y)
else:
    if vx!=0: 
        if vx>0: # colide right 
            colsx.append([(l-x)/vx  ,l])# first collision time
            left=True
            for i in range(K-1):
                # print(colsx)
                xc=0 if left else l
                left=not left
                s=colsx[-1][0] #last time
                colsx.append([s+(l/vx),xc])# time of next collision
        else: # colide left
            colsx.append([(x+1)/(-vx),0])
            right=True
            for i in range(K-1):
                xc=l if right else 0
                right=not right
                s=colsx[-1][0]
                colsx.append([s+(l/vx),xc])


    colsy=[]
    #y time to colide
    if vy!=0: 
        if vy>0: # colide right 
            colsy.append([(h-y)/vy  ,h])# first collision time
            left=True
            for i in range(K-1):
                # print(colsy)
                yc=0 if left else h
                left=not left
                s=colsy[-1][0] #last time
                colsy.append([s+(h/vy),yc])# time of neyt collision
        else: # colide left
            colsy.append([(y+1)/(-vy),0])
            right=True
            for i in range(K-1):
                yc=h if right else 0
                right=not right
                s=colsy[-1][0]
                colsy.append([s+(h/vy),yc])

    # print(colsx)
    # print(colsy)
    if vx==0:
        print (x,colsy[-1][1])
    elif vy==0:
        print(colsx[-1][1],y)
    else:
        s=0 
        i,j=0,0
        colidedx=True
        while K:
            if colsx[i][0]<colsy[j][0]: #colx before 
                # print(colsx[i])
                colidedx=True
                i+=1
                
            elif colsx[i][0]>colsy[j][0]: #colx before 
                # print(colsy[j])
                colidedx=False
                j+=1
            else:
                i+=1
                j+=1
            K-=1
        i-=1
        j-=1
        lasttx=colsx[i][0]
        lastty=colsy[j][0]

        # print(lasttx)
        # print(lastty)
        # print(colidedx)
        if colidedx: # lawej y
            # print("searching y")
            x=colsx[i][1]
            if colsy[j][1]==h:
                y=(h-abs(vy)*(lasttx-lastty))
            else:
                y=(abs(vy)*(lasttx-lastty))
                while y < 0 :
                    y+=h 
        else: # lawej x
            # print(print("searching x"))
            y=colsy[j][1]
            if colsx[i][1]==l:
                # print()
                x=(l-abs(vx)*(lastty-lasttx))
            else:
                x=(abs(vx)*(lastty-lasttx))
                while x < 0 :
                    x+=l 
        print(floor(x),floor(y))