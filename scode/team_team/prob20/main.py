def cwining(m, p):
    r = len(m)
    cols = len(m[0])

    def test_line(row, col, dr, dc):
        for _ in range(3):
            row += dr
            col += dc
            if not (0 <= row < r and 0 <= col < cols) or m[row][col] != p:
                return False
        return True

    for row in range(r):
        for col in range(cols):
            if m[row][col] == 0:
                if col <= cols - 4 and test_line(row, col, 0, 1):
                    return True
                if row <= r - 4 and test_line(row, col, 1, 0):
                    return True
                if row <= r - 4 and col <= cols - 4 and test_line(row, col, 1, 1):
                    return True
                if row >= 3 and col <= cols - 4 and test_line(row, col, -1, 1):
                    return True

    return False
def test_connect_four(m):
    r = len(m)
    cols = len(m[0])

    def test_line(row, col, dr, dc):
        p = m[row][col]
        if p == 0:
            return False

        for _ in range(3):
            row += dr
            col += dc
            if not (0 <= row < r and 0 <= col < cols) or m[row][col] != p:
                return False

        return True

    def count_p_pieces(p):
        return sum(row.count(p) for row in m)

    def predict_next():
        count_p_1 = count_p_pieces(1)
        count_p_2 = count_p_pieces(2)

        if count_p_1 > count_p_2:
            return 2
        else:
            return 1

    next = predict_next()

    for row in range(r):
        for col in range(cols):
            if col <= cols - 4 and test_line(row, col, 0, 1):
                return next, m[row][col]
            if row <= r - 4 and test_line(row, col, 1, 0):
                return next, m[row][col]
            if row <= r - 4 and col <= cols - 4 and test_line(row, col, 1, 1):
                return next, m[row][col]
            if row >= 3 and col <= cols - 4 and test_line(row, col, -1, 1):
                return next, m[row][col]

    return next, 0

roo,coo = map(int,input().split())
board =[]
for j in range(roo):
    ch = input()
    board.append([int(x) for x in ch])

next, winner = test_connect_four(board)

if winner == 0:
    print(next*cwining(board,next))
else:
    print(winner)











