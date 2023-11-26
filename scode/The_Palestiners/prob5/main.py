def is_under_attack(rook_position, black_king_position, white_king_position):
    rook_row, rook_col = ord(rook_position[1]) - ord('0'), ord(rook_position[0]) - ord('a') + 1
    black_king_row, black_king_col = ord(black_king_position[1]) - ord('0'), ord(black_king_position[0]) - ord('a') + 1
    white_king_row, white_king_col = ord(white_king_position[1]) - ord('0'), ord(white_king_position[0]) - ord('a') + 1

    # Check if the rook can capture the white king horizontally or vertically
    if rook_row == white_king_row or rook_col == white_king_col:
        return "YES"
    else:
        return "NO"

# Test cases
rook_position = input().strip()
black_king_position = input().strip()
white_king_position = input().strip()

result = is_under_attack(rook_position, black_king_position, white_king_position)
print(result)
  