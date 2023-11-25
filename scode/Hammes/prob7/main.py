def min_moves_to_unlock(n, z, levels):
    levels.sort(key=lambda x: x[1])
    moves = 0
    stars = 0

    for i in range(n):
        if stars == z:
            break

        if levels[i][1] <= stars:
            stars += 2
        else:
            stars += 1

        moves += 1

    return moves

# Input parsing
n, z = map(int, input().split())
levels = [tuple(map(int, input().split())) for _ in range(n)]

# Output result
result = min_moves_to_unlock(n, z, levels)
print(result)
