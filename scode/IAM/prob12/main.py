try:
    Nb_L, Nb_c = map(int, input().split())
    Pos_Gx, Pos_Gy, Pos_Px, Pos_Py = map(int, input().split())
    Nb_obstacle = input()
    Nb_obstacle = int(Nb_obstacle)
    Obstacle_List = [None] * Nb_obstacle
    steps = 0
    i = Nb_L * Nb_c
    for j in range(Nb_obstacle):
        tempx, tempy = map(int, input().split())
        Obstacle_List[j] = str(tempx) + str(tempy)


    def check(Temp_shortest, G_x, G_y):
        global Pos_Gx, Pos_Gy, steps
        if (((abs(G_x - Pos_Px) + abs(
                G_y - Pos_Py)) < Temp_shortest) and G_x < Nb_c and G_x > -1 and G_y < Nb_L and G_y > -1):
            exists = False
            for e in Obstacle_List:
                if (e == str(G_x) + str(G_y)):
                    exists = True
            if (exists == False):
                Pos_Gx = G_x
                Pos_Gy = G_y
                steps = steps + 1
                Temp_shortest = abs(G_x - Pos_Px) + abs(G_y - Pos_Py)


    def checkNeighbors(Pos_Gx, Pos_Gy):
        G_x = Pos_Gx
        G_y = Pos_Gy
        Temp_shortest = abs(G_x - Pos_Px) + abs(G_y - Pos_Py)
        global steps
        G_x = G_x - 1
        G_y = G_y - 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)
        G_x = G_x + 1
        G_y = G_y - 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)
        G_x = G_x + 1
        G_y = G_y - 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)
        G_y = G_y + 1
        check(Temp_shortest, G_x, G_y)


    while (i > 0 and abs(Pos_Gx - Pos_Px) + abs(Pos_Gy - Pos_Py) > 0):
        checkNeighbors(Pos_Gx, Pos_Gy)
        i = i - 1
    if (abs(Pos_Gx - Pos_Px) + abs(Pos_Gy - Pos_Py) > 0):
        print("0")
    else:
        print(steps)
except ValueError:
    print('INPUT_ERROR')
