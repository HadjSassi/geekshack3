def check_connect_four(matrix):
    def check_line(line):
        for i in range(len(line) - 3):
            if line[i] == line[i + 1] == line[i + 2] == line[i + 3] != 0:
                return line[i]
        return False
    for row in matrix:
        if check_line(row):
            return True
    for col in range(len(matrix[0])):
        column = [matrix[row][col] for row in range(len(matrix))]
        if check_line(column):
            return check_line(column)
    for row in range(len(matrix) - 3):
        for col in range(len(matrix[0]) - 3):
            diag = [matrix[row + i][col + i] for i in range(4)]
            if check_line(diag):
                return check_line(diag)
    for row in range(3, len(matrix)):
        for col in range(len(matrix[0]) - 3):
            diag = [matrix[row - i][col + i] for i in range(4)]
            if check_line(diag):
                return check_line(diag)

    return 0
r,c = map(int,input().split())
board =[]
for j in range(r):
    board.append(input().split())


result = check_connect_four(board)
print(result)