import sys
sys.setrecursionlimit(9000)


n, z = [int(i) for i in input().split()]


l = []
for i in range(n):
    s = [int(i) for i in input().split()]
    l.append(s)

min_penalty = float('inf')

def dfs(stars, progress: int, moves: int, min_penalty):
    
    if stars >= z:
        min_penalty = min(min_penalty, moves)
        return moves
    
    if moves >= min_penalty:
        return float('inf')
    
    if progress == len(l):
        return float('inf')
    if z-stars > 2*(len(l)-progress):
        return float('inf')


    
    a = dfs(stars+1, progress+1, moves + l[progress][0], min_penalty)
    b = dfs(stars+2, progress+1, moves + l[progress][1], min_penalty)
    c = dfs(stars, progress+1, moves, min_penalty)
    return min(a,b,c)


print(dfs(0, 0, 0, min_penalty))  