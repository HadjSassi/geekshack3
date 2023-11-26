def can_win_in_next_move(matrix, player):
    rows = len(matrix)
    cols = len(matrix[0])

    def check_line(row, col, dr, dc):
        for _ in range(3):
            row += dr
            col += dc
            if not (0 <= row < rows and 0 <= col < cols) or matrix[row][col] != player:
                return False
        return True

    for row in range(rows):
        for col in range(cols):
            if matrix[row][col] == 0:
                if col <= cols - 4 and check_line(row, col, 0, 1):
                    return True
                if row <= rows - 4 and check_line(row, col, 1, 0):
                    return True
                if row <= rows - 4 and col <= cols - 4 and check_line(row, col, 1, 1):
                    return True
                if row >= 3 and col <= cols - 4 and check_line(row, col, -1, 1):
                    return True

    return False
def check_connect_four(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    def check_line(row, col, dr, dc):
        player = matrix[row][col]
        if player == 0:
            return False

        for _ in range(3):
            row += dr
            col += dc
            if not (0 <= row < rows and 0 <= col < cols) or matrix[row][col] != player:
                return False

        return True

    def count_player_pieces(player):
        return sum(row.count(player) for row in matrix)

    def predict_next_player():
        count_player_1 = count_player_pieces(1)
        count_player_2 = count_player_pieces(2)

        if count_player_1 > count_player_2:
            return 2
        else:
            return 1

    next_player = predict_next_player()

    for row in range(rows):
        for col in range(cols):
            if col <= cols - 4 and check_line(row, col, 0, 1):
                return next_player, matrix[row][col]
            if row <= rows - 4 and check_line(row, col, 1, 0):
                return next_player, matrix[row][col]
            if row <= rows - 4 and col <= cols - 4 and check_line(row, col, 1, 1):
                return next_player, matrix[row][col]
            if row >= 3 and col <= cols - 4 and check_line(row, col, -1, 1):
                return next_player, matrix[row][col]

    return next_player, 0

roo,coo = map(int,input().split())
board =[]
for j in range(roo):
    ch = input()
    board.append([int(x) for x in ch])

next_player, winner = check_connect_four(board)

if winner == 0:
    print(next_player*can_win_in_next_move(board,next_player))
else:
    print(winner) 