def contour(m, x, y, test):
    if (str(m[x][y]) == "*"):
        return (0)
    elif (test == "d"):
        if (str(m[x + 1][y - 1]))=="*" :
            return (0)
        elif (str(m[x + 1][y - 1]) != "*" ):
          return (1)
        elif (str(m[x + 1][y])=="*") :
          return (0)
        else:
          return (1)

    elif (test == "l"):
         if (str(m[x][y - 1])=="*"):
            return (0)
         else:
             return (1)
    elif (test=="u"):
         if (str(m[x-1][y + 1])=="*"):
            return (0)
         else:
             return (1)
while (1):

    try:
        nb_L, Nb_c = [int(x) for x in input().split()]
    except:
        (print("INPUT_ERROR"))
    else:
        break
m=[]
L=[]
for j in range(Nb_c):
    L.append(0)
for i in range (nb_L):
    m.append(L)
    

while (1):
    try:
        Pos_Gx, Pos_Gy, Pos_Px, Pos_Py = [int(x) for x in input().split()]
    except:
         print("INPUT_ERROR")
    else:
        break

m[Pos_Gx][Pos_Gy] = 1

m[Pos_Px][Pos_Py] = 2

while (1):
    try:
        Nb_obstacle = int(input())
    except:
        print("INPUT_ERROR")
    else:
        break

    for i in range(Nb_obstacle):
        do 
        {
            x, y = [int(x) for x in input().split()];
        }
        while (x[0] == Pos_Gx and y[0] == Pos_Gy ) or ( x[0] == Pos_Gx  and y[0] == Pos_Py  )
        m[x][y] = "*";
        
        

move = 0

while ((Pos_Gx != Pos_Px) and (Pos_Gy != Pos_Py)):
    if (Pos_Gx > Pos_Px):

        if Pos_Gy > Pos_Py:
            if contour(m, (Pos_Gx + 1), (Pos_Gy - 1), "d"):
                Pos_Gx = Pos_Gx + 1
                Pos_Gy = Pos_Gy - 1
                move += 1

            elif contour(m, Pos_Gx + 1, Pos_Gy, "d"):
                Pos_Gx = Pos_Gx + 1
                move += 1
            elif contour(m, Pos_Gx, Pos_Gy - 1, "d"):
                Pos_Gy = Pos_Gy - 1
                move += 1
            elif contour(m, Pos_Gx + 1, Pos_Gy + 1, "d"):
                Pos_Gx = Pos_Gx + 1
                Pos_Gy = Pos_Gy + 1
                move += 1
            else:
                print ("0")





        elif (Pos_Gy < Pos_Py):
            if contour(m, Pos_Gx + 1, Pos_Gy + 1, "d"):
                Pos_Gx = Pos_Gx + 1
                Pos_Gy = Pos_Gy + 1
                move += 1
            elif contour(m, Pos_Gx + 1, Pos_Gy, "d"):
                Pos_Gx = Pos_Gx + 1
                move += 1
            elif contour(m, Pos_Gx, Pos_Gy + 1, "d"):
                Pos_Gy = Pos_Gy + 1
                move += 1
            elif contour(m, Pos_Gx + 1, Pos_Gy - 1, "d"):
                Pos_Gx = Pos_Gx + 1
                Pos_Gy = Pos_Gy - 1
                move += 1
            else:
                print ("0")



    elif (Pos_Gx < Pos_Px):

        if (Pos_Gy > Pos_Py):
            if contour(m, Pos_Gx - 1, Pos_Gy - 1, "u"):
                Pos_Gx = Pos_Gx - 1
                Pos_Gy = Pos_Gy - 1
                move += 1

            elif contour(m, Pos_Gx - 1, Pos_Gy, "u"):
                Pos_Gx = Pos_Gx - 1
                move += 1
            elif contour(m, Pos_Gx, Pos_Gy - 1, "u"):
                Pos_Gy = Pos_Gy - 1
                move += 1
            elif contour(m, Pos_Gx - 1, Pos_Gy + 1, "u"):
                Pos_Gx = Pos_Gx - 1
                Pos_Gy = Pos_Gy + 1
                move += 1
            else:
                print ("0")


        elif Pos_Gy < Pos_Py:
            if contour(m, Pos_Gx - 1, Pos_Gy + 1, "u"):
                Pos_Gx = Pos_Gx - 1
                Pos_Gy = Pos_Gy + 1
                move += 1
            elif contour(m, Pos_Gx - 1, Pos_Gy, "u"):
                Pos_Gx = Pos_Gx - 1
                move += 1
            elif contour(m, Pos_Gx, Pos_Gy + 1, "u"):
                Pos_Gy = Pos_Gy + 1
                move += 1
            elif contour(m, Pos_Gx - 1, Pos_Gy - 1, "u"):
                Pos_Gx = Pos_Gx - 1
                Pos_Gy = Pos_Gy - 1
                move += 1
            else :
                print ("0")



    elif Pos_Gx == Pos_Px:

        if Pos_Gy > Pos_Py:
            if contour(m, Pos_Gx, Pos_Gy - 1, "l"):
                Pos_Gy -= 1
                move += 1
            elif contour(m, Pos_Gx + 1, Pos_Gy - 1, "l"):
                Pos_Gx = Pos_Gx + 1
                Pos_Gy + Pos_Gy - 1
                move += 1

if (Pos_Gx == Pos_Px) and (Pos_Gy == Pos_Py):
    print(move)
 