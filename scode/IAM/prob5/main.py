def allInput(n):
    lAll = []
    lMain = []
    lBrancheA = []
    lBrancheB = []
    for i in range(n):
        ch = input()
        if (ch.startswith("BR Main") ):
            if (ch != "BR Main"):
                lMain.append(ch[8:])
        elif (ch[3:].startswith("A")):
            lBrancheA.append(ch[5:])
        else:
            lBrancheB.append(ch[5:])
    lAll.append(lMain)
    lAll.append(lBrancheA)
    lAll.append(lBrancheB)
    return lAll


def cylable(e, l):
    lt1 = []
    for i in l:
        if (i[0] == e[0]):
            return (True, i)
    else:
        return (False, -1)


def addWrite(lAll):
    l1 = []
    l2 = []
    t = 0
    x = len(lAll[1])
    y = len(lAll[2])
    for i in range(min(x, y)):
        if (t == 0):
            l2.append(lAll[1][0])
            del (lAll[1][0])
            t = 1
        if (t == 1):
            l2.append(lAll[2][0])
            del (lAll[2][0])
            t = 0
    if (lAll[1] != []):
        l2.extend(lAll[1])
    elif (lAll[2] != []):
        l2.extend(lAll[2])

    for e in l2:
        if (e in lAll[0]):
            l1.append(e)
            lAll[0].remove(e)
        elif (cylable(e, lAll[0])[0] and e not in lAll[0]):
            l1.append(e + " : M")
            lAll[0].remove(cylable(e, lAll[0])[1])
        elif (e not in lAll[0]):
            l1.append(e + " : U")
    if (lAll[0] != []):
        j = 0
        for e in lAll[0]:
            l1.append(e)
    for e in l1:
        print(e)


try:
    n = input()
except EOFError:
    print("NO")

else:
    n = int(n)
    alle = allInput(n)
    addWrite(alle) 