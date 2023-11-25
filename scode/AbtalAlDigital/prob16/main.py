def  rech(roads, s,l):
    count=0
    d=[]
    for road in roads:

        if road[0] == s:
            if road[2] > l:
                if [road[0], road[1], road[2] - l] not in d:
                    count += 1
                    d.append([road[0], road[1], road[2] - l])

            elif road[2] == l and road[1] not in d:
                d.append(road[1])
                count += 1
            else:
                if rech(roads, road[1], l - road[2]) > 0:
                    count += 1


    return (count)

n=tuple(map(int, input().split()))
roads = [tuple(map(int, input().split())) for _ in range(n[1])]
l=int(input())

s=n[2]
print(rech(roads,s,l))



