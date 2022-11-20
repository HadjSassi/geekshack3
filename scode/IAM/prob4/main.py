try:
    arrayOfValues = []
    arrayOfValues2 = []
    Msize = int(input())
    Matrix = [[0 for x in range(6)] for y in range(Msize)]

    def checkDown(x, y):
        # print("Checking down for ", y)
        cons = 0
        if x > Msize-1:
            # print("down::out of the box")
            return 0
        if y < 5:
            if Matrix[x][y+1]==1 and Matrix[x][y-1]==1:
                # print('one before and after on the horizontal axes')
                return 0
        # print('checking down for the range',range(Msize-x))
        for i in range(Msize-x):
            # print("down::", i+x, ' ', y)
            if Matrix[i+x][y]==1:
                cons += 1
                Matrix[i+x][y] = 0
                if i+x == Msize or Matrix[i+x][y] == 0:
                    if Matrix[i+x-1][y-1] == 1 and Matrix[i+x-1][y+1] == 0:
                        for l in range(1, y):
                            if Matrix[i+x][y-l]==1:
                                Matrix[i+x][y-l] = 0
                                cons += 1
                            else:
                                break
                    elif Matrix[i+x][y+1] == 1 and Matrix[i+x][y-1] == 0:
                        for g in range(1, 6-y):
                            if Matrix[i+x][g-y]==1:
                                cons += 1
                                Matrix[i+x][g-y] = 0

            else:
                break
        return cons

    def checkDown2(x, y):
        # print("Checking down for ", y)
        cons = 0
        if x > Msize-1:
            # print("down::out of the box")
            return 0
        if y < 5:
            if Matrix[x][y+1] == 2 and Matrix[x][y-1] == 2:
                # print('one before and after on the horizontal axes')
                return 0
        # print('checking down for the range',range(Msize-x))
        for i in range(Msize-x):
            # print("down::", i+x, ' ', y)
            if Matrix[i+x][y] == 2:
                cons += 1
                Matrix[i+x][y] = 0
                if i+x == Msize or Matrix[i+x][y] == 0:
                    if Matrix[i+x-1][y-1] == 2 and Matrix[i+x-1][y+1] == 0:
                        for l in range(1, y):
                            if Matrix[i+x][y-l]:
                                Matrix[i+x][y-l] = 0
                                cons += 1
                            else:
                                break
                    elif Matrix[i+x][y+1] == 2 and Matrix[i+x][y-1] == 0:
                        for g in range(1, 6-y):
                            if Matrix[i+x][g-y]:
                                cons += 1
                                Matrix[i+x][g-y] = 0

            else:
                break
        return cons

    nothing = True

    def resetDown(x, y):
        for i in range(Msize-x-1):
            if Matrix[i+x][y]:
                Matrix[i+x][y] = 0
    def resetDown2(x, y):
        for i in range(Msize-x-1):
            if Matrix[i+x][y]==2:
                Matrix[i+x][y] = 0
    r = 0
    while r < Msize:
        c = list(map(str, input().split()))
        if(c.__len__() < 1 or c.__len__() == 1 and c[0] == 0):
            break

        for k in range(c.__len__()):
            if c[k] == 'S':
                Matrix[r][k] = 1
            elif c[k] == 'T':
                Matrix[r][k] = 2
        nothing = False
        r += 1
    if(nothing):
        print('NO')

    def printMatrix():
        for i in range(Msize):
            print('')
            for j in range(6):
                print(Matrix[i][j], end='')
    # printMatrix()
    # print('')
    for index in range(Msize):
        consecutive_rails = 0
        for rail in range(6):
            # print(index, ' ', rail)
            if Matrix[index][rail]:
                Matrix[index][rail] = 0
                consecutive_rails += 1
                down = checkDown(index+1, rail)
                # print('down result ', down)
                if down > 0:
                    resetDown(index, rail)
                    consecutive_rails += down
                # printMatrix()
                # print('')
            else:
                if(consecutive_rails > 0):
                    arrayOfValues.append(consecutive_rails)
                # print('resetting consecutive_rails')
                consecutive_rails = 0
        if(consecutive_rails > 0):
            arrayOfValues.append(consecutive_rails)
    for index in range(Msize):
        consecutive_rails = 0
        for rail in range(6):
            # print(index, ' ', rail)
            if Matrix[index][rail] == 2:
                Matrix[index][rail] = 0
                consecutive_rails += 1
                down = checkDown2(index+1, rail)
                # print('down result ', down)
                if down > 0:
                    resetDown2(index, rail)
                    consecutive_rails += down
                # printMatrix()
                # print('')
            else:
                if(consecutive_rails > 0):
                    arrayOfValues2.append(consecutive_rails)
                # print('resetting consecutive_rails')
                consecutive_rails = 0
        if(consecutive_rails > 0):
            arrayOfValues2.append(consecutive_rails)
    arrayOfValues = list(dict.fromkeys(arrayOfValues))
    arrayOfValues2 = list(dict.fromkeys(arrayOfValues2))
    arrayOfValues.sort()
    arrayOfValues2.sort()
    print('S ', end='')
    for i in range(arrayOfValues.__len__()):
        print(arrayOfValues[i]*100, ' ', end='')
    print('')
    print('T ', end='')
    for i in range(arrayOfValues2.__len__()):
        print(arrayOfValues2[i]*100, ' ', end='')
except ValueError:
    print('NO')
except EOFError:
    print("NO")
