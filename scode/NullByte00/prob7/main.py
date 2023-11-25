n, z = [int(i) for i in input().split()]


l = []
for i in range(n):
    s = [int(i) for i in input().split()]
    l.append(s)

def dfs(l, z, stars, progress: int , chosen: list, penalty: int, dp):
    if stars >= z:
        return penalty
    if progress == len(l):
        return float('inf')
    if (progress,penalty, stars) in dp:
        return dp[(progress, penalty, stars)]
    
    
    # chosen.append(l[progress][0])
    a = dfs(l, z, stars+1, progress+1, chosen + [l[progress][0]], penalty + l[progress][0], dp)
    b = dfs(l, z, stars+2, progress+1, chosen + [l[progress][1]], penalty + l[progress][1], dp)
    c = dfs(l, z, stars, progress+1, chosen, penalty, dp)
    
    result = min(a,b,c)
    dp[(progress, penalty, stars)] = result
    return result

dp = {}
print(dfs(l, z, 0, 0, [], 0, dp))
    