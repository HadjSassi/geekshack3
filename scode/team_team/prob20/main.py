nl,nc=map(int,input().split())
l=[]
for i in range(nl):
    l=l+[input()]
def vert_win(letter):
    for x in range(nl-1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x - 1][y] == l[x - 2][y] == l[x - 3][y] == letter:
                    return True
                else:
                    continue
            except IndexError:
                continue
def horiz_win(letter):
    for x in range(nl-1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x][y + 1] == l[x][y + 2] == l[x][y + 3] == letter:
                    return True
                else:
                    continue
            except IndexError:
                continue


def diag_win(letter):
    for x in range(nl-1, -1, -1):
        for y in range(nc):
            try:
                if l[x][y] == l[x - 1][y + 1] == l[x - 2][y + 2] == l[x - 3][y + 3] == letter:
                    return True
                elif l[x][y] == l[x - 1][y - 1] == l[x - 2][y - 2] == l[x - 3][y - 3] == letter:
                    return True
            except IndexError:
                continue

if vert_win('1')or horiz_win('1')or diag_win('1') :
        print(1)

elif vert_win('2')or horiz_win('2')or diag_win('2'):
        print(2)
else :
    print(0)