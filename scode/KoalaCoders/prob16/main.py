def is_prefix(lst1, lst2):
    return all(x == y for x, y in zip(lst1, lst2))
def find_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if start not in graph:
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            new_paths = find_paths(graph, node, end, path)
            paths.extend(new_paths)
    return paths
def distances(all_paths, paths):
    distances_list = []
    for d in all_paths:
        s = sum(int(p[2]) for j in range(len(d)-1) for p in paths if d[j] == p[0] and d[j+1] == p[1])
        distances_list.append(s)
    return distances_list

n, m, s = map(int, input().split())
paths = [input().split() for _ in range(m)]
l = int(input())
graph = {str(city): [p[1] for p in paths if p[0] == str(city)] for city in range(1, n + 1)}

da = []
for city in range(1, n + 1):
    all_paths = find_paths(graph, str(s), str(city))
    dis = distances(all_paths, paths)
    if dis and min(dis) >= l:
        da += all_paths
da = sorted(da)
i = 0
while i < len(da) - 1:
    if is_prefix(da[i], da[i+1]):
        da.pop(i+1)
    else:
        i += 1
lfinal = [[] for _ in range(n)]
for city in range(1, n + 1):
    lfinal[city-1] = [jojo for jojo in da if jojo[-1] == str(city)]
score = sum(len(set(distances(k, paths))) for k in lfinal if k)
print(score) 