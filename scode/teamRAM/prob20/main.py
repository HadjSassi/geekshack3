def favorable(gridd, player):
    rows = len(gridd)
    cols = len(gridd[0])

    def ctrll(lig, col, r, c):
        for i in range(3):
            lig += r
            col += c
            if not (0 <= lig < rows and 0 <= col < cols) or gridd[lig][col] != player:
                return False
        return True

    for lig in range(rows):
        for colonne in range(cols):
            if gridd[lig][colonne] == 0:
                if colonne <= cols - 4 and ctrll(lig, colonne, 0, 1):
                    return True
                if lig <= rows - 4 and ctrll(lig, colonne, 1, 0):
                    return True
                if lig <= rows - 4 and colonne <= cols - 4 and ctrll(lig, colonne, 1, 1):
                    return True
                if lig >= 3 and colonne <= cols - 4 and ctrll(lig, colonne, -1, 1):
                    return True

    return False
def ctrlconnFour(gridd):
    rows = len(gridd)
    cols = len(gridd[0])

    def ctrll(row, col, r, c):
        player = gridd[row][col]
        if player == 0:
            return False

        for f in range(3):
            ligne += r
            colonne += c
            if not (0 <= ligne < rows and 0 <= colonne < cols) or gridd[ligne][colonne] != player:
                return False

        return True

    def PieceJouees(player):
        return sum(row.count(player) for row in gridd)

    def prochainsPas():
        nb1 = PieceJouees(1)
        nb2 = PieceJouees(2)

        if nb1 > nb2:
            return 2
        else:
            return 1

    pj = prochainsPas()

    for ligne in range(rows):
        for colonne in range(cols):
            if colonne <= cols - 4 and ctrll(ligne, colonne, 0, 1):
                return pj, gridd[ligne][col]
            if ligne <= rows - 4 and ctrll(ligne, colonne, 1, 0):
                return pj, gridd[ligne][colonne]
            if ligne <= rows - 4 and colonne <= cols - 4 and ctrll(ligne, colonne, 1, 1):
                return pj, gridd[ligne][col]
            if ligne >= 3 and colonne <= cols - 4 and ctrll(ligne, colonne, -1, 1):
                return pj, gridd[ligne][colonne]

    return pj, 0

nbl,nbc = map(int,input().split())
jeu =[]
for j in range(nbl):
    ch = input()
    jeu.append([int(z) for z in ch])

pj, joueurGagnant = ctrlconnFour(jeu)

if joueurGagnant == 0:
    print(pj*favorable(jeu,pj))
else:
    print(joueurGagnant)
