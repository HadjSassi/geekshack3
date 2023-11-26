def winVertical(board):
    for x in range(rows):
        for y in range(columns):
            if (board[x][y] == '1' and board[x+1][y] == '1' and board[x+2][y] == '1' and board[x+3][y] == '1'):
                #print "Winner == Red player"
                return 1
                break
            elif (board[x][y] == '2' and board[x+1][y] == '2' and board[x+2][y] == '2' and board[x+3][y] == '2'):
                #print "Winner == Black player"
                return 2
                break
    return 0
def winHorizontal(board):
    for x in range(rows):
        for y in range(columns):
            if (board[x][y] == '1' and board[x][y+1] == '1' and board[x][y+2] == '1' and board[x][y+3] == '1'):
                #print "Winner == Red player"
                return 1
                break
            elif (board[x][y] == '2' and board[x][y+1] == '2' and board[x][y+2] == '2' and board[x][y+3] == '2'):
                #print "Winner == Black player"
                return 2
                break
    return 0


def winDiagonal(board):   
    for x in range(rows):
        for y in range(columns):
            if (board[x][y] == '1' and board[x+1,y+1] == '1' and board[x+2,y+2] == '1' and board[x+3,y+3] =='1'):
                #print "Winner == Red player"
                return 1
            elif (board[x][y] == '2' and board[x+1,y+1] == '2' and board[x+2,y+2] == '2' and board[x+3,y+3] =='2'):
                #print "Winner == Black player"
                return 2
            elif (board[x][y] == '1' and board[x-'1',y-'1'] == '1' and board[x-'2',y+2] == '1' and board[x-3,y+3] =='1'):
                #print "Winner == Red player"
                return 1
            elif (board[x][y] == '2' and board[x-'1',y-'1'] == '2' and board[x-'2',y+2] == '2' and board[x-3,y+3] =='2'):
                #print "Winner == Black player"
                return 2
    return 0

def win(board):
    res=0
    try :
        res += winVertical(board)
    except :
        pass
    try :
        res +=  winHorizontal(board)
    except :
        pass
    try :
        res +=  winDiagonal(board)
    except :
        pass
    return res



global rows
global columns

rows , columns = list(map(lambda x:int(x),input().split()))
l= []
for i in range(rows):
    l.append(list(*map(lambda x:x,input().split())))
print(win(l))  