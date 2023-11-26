def count(graph, start, l):
    v= set()
    s = [(start, 0)]  
    ms=0
    while s:
        city,distance = s.pop()
        if distance == l:
            ms+= 1
        v.add(city)
        for n,r in graph[city]:
            if n not in v:
                s.append((n,distance + r))
    return ms
def main():
    graph = dict(list)
    for i in range(m):
        vi, ui, wi = map(int, input().split())
        graph[vi].append((ui, wi))
        graph[ui].append((vi, wi))
        l=int(input())
        for i in range(m):
          n, m, s = map(int, input().split())
          result=count(graph,s,l)
          print(result)
   