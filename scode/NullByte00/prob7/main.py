n, z = [int(i) for i in input().split()]


l = []
for i in range(n):
    s = [int(i) for i in input().split()]
    l.append(s)

def dfs(stars, progress: int, moves: int):
    if stars >= z:
        return moves
    if progress == len(l):
        return float('inf')
    
    # chosen.append(l[progress][0])
    a = dfs(stars+1, progress+1, moves + l[progress][0])
    b = dfs(stars+2, progress+1, moves + l[progress][1])
    c = dfs(stars, progress+1, moves)
    return min(a,b,c)


print(dfs(0, 0, 0))