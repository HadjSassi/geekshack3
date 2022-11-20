x, y = map(int, input().strip().split())
dx, dy = map(int, input().strip().split())
h, o = map(int, input().strip().split())

humans = []
for i in range(h):
    humans.append(list(map(int, input().strip().split())))


obstacles = []
for i in range(o):
    obstacles.append(list(map(int, input().strip().split())))

def fun(l):
    return abs(dx-l[0])+abs(dy-l[1])

humans.sort(key=fun)


dis = 0
for i in range(len(humans)-1):
    dis += abs(humans[i][0]-humans[i+1][0])+abs(humans[i][1]-humans[i+1][1])
    
dis += abs(dx-humans[len(humans)-1][0])+abs(dy-humans[len(humans)-1][1])
dis += abs(dx-humans[0][0])+abs(dy-humans[0][1])

print(dis)
    
      