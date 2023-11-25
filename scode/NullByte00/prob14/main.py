n, z = [int(i) for i in input().split()]


l = []
for i in range(n):
    s = [int(i) for i in input().split()]
    l.append(s)

def dfs(l, z, stars, progress: int , chosen: list, penalty: int):
    if stars == z:
        return penalty
    if progress == len(l):
        return float('inf')
    
    # chosen.append(l[progress][0])
    a = dfs(l, z, stars+1, progress+1, chosen + [l[progress][0]], penalty + l[progress][0])
    b = dfs(l, z, stars+2, progress+1, chosen + [l[progress][1]], penalty + l[progress][1])
    c = dfs(l, z, stars, progress+1, chosen, penalty)
    return min(a,b,c)


print(dfs(l, z, 0, 0, [], 0))
    