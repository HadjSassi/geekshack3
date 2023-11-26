nl, nc = map(int, input().split())
l = []
nb1 = 0
nb2 = 0
for i in range(nl):
    ch = input()
    nb1 += ch.count('1')
    nb2 += ch.count('2')
    l = l + [list(ch)]
def vert_win(letter):
    for x in range(nl - 1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x - 1][y] == l[x - 2][y] == l[x - 3][y] == letter:
                    return True
                else:
                    continue
            except IndexError:
                continue


def horiz_win(letter):
    for x in range(nl - 1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x][y + 1] == l[x][y + 2] == l[x][y + 3] == letter:
                    return True
                else:
                    continue
            except IndexError:
                continue


def diag_win(letter):
    for x in range(nl - 1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x - 1][y + 1] == l[x - 2][y + 2] == l[x - 3][y + 3] == letter:
                    return True
                elif l[x][y] == l[x - 1][y - 1] == l[x - 2][y - 2] == l[x - 3][y - 3] == letter:
                    return True
            except IndexError:
                continue


if vert_win('1') or horiz_win('1') or diag_win('1'):
    print(1)

elif vert_win('2') or horiz_win('2') or diag_win('2'):
    print(2)
else:
    if (nb1 == nb2):
        i = nl - 1
        j = 0
        while (j < nc):
            while (i >= 0):
                if l[i][j] == '0':
                    l[i][j] = '1'
                    if vert_win('1') or horiz_win('1') or diag_win('1'):
                        print(1)
                        exit()
                    else:
                        l[i][j] = '0'
                        j = j + 1
                else:
                    i -= 1
    else:
        i = nl - 1
        j = 0
        while (j < nc):
            while (i >= 0):
                if l[i][j] == '0':
                    l[i][j] = '2'
                    if vert_win('2') or horiz_win('2') or diag_win('2'):
                        print(2)
                        exit()
                    else:
                        l[i][j] = '0'
                        j = j + 1
                else:
                    i -= 1














