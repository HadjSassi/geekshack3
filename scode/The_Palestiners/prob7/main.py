
def min_moves_to_unlock(n, z, levels):
    levels.sort(key=lambda x: (x[1], x[0]))  # Sort levels by the minimum moves needed for two stars and then one star
    stars_collected = 0
    moves_required = 0

    for level in levels:
        if stars_collected >= z:
            break

        if level[1] <= stars_collected:
            stars_collected += 2
        elif level[0] <= stars_collected:
            stars_collected += 1
        else:
            moves_required += 1
            stars_collected += 1

    if stars_collected < z:
        print("Impossible to achieve the required stars.")
        return -1

    return moves_required

# Input
n, z = map(int, input().split())
levels = [list(map(int, input().split())) for _ in range(n)]

# Output
result = min_moves_to_unlock(n, z, levels)
if result != -1:
    print(result)