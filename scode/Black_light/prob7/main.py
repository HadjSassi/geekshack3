n,z=map(int,input().split)
levels=list()

 a,b=map(int,input().split)
 list.append(a,b)
 def min_moves_to_unlock(n, z, levels):
    levels.sort(key=lambda x: x[1] - x[0])

    one_star_levels = [a for a, b in levels]
    two_star_levels = [b for a, b in levels]

    moves_for_one_star = sum(one_star_levels)
    additional_moves_for_two_stars = sum(b - a for a, b in levels)

    total_moves = moves_for_one_star
    stars_collected = n  # because we get one star for each level initially

    for i in range(n):
        if stars_collected < z:
            total_moves += levels[i][1] - levels[i][0]
            stars_collected += 1  # We gain one additional star for the upgrade

    return total_moves

  