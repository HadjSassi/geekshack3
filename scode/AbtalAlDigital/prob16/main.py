def rech(roads, capitale, longeur,s):
    if longeur <= 0:
        s.append(1)

    for road in roads:
        if road[0] == capitale:
            new_road = [r for r in roads if r != road]
            return s.count(1) + rech(new_road, road[1], longeur - road[2],s)
    return s.count(1)

n = tuple(map(int, input().split()))
roads = [tuple(map(int, input().split())) for _ in range(n[1])]
longeur = int(input())
s=[]
capitale = n[2]
print(rech(roads, capitale, longeur, []))