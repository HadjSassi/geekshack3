def rech(road, longeur,s):
    longeur=longeur -road[2]
    if longeur <= 0:
        s.append[1]
    
    if cherche_road(roads,road[1]) == 0:
        return 0
    return nombre + rech(cherche_road(roads,road[1]),longeur,nombre)
    
    
def cherche_road(roads,cite):
    for i in range(len(roads)):
        if cite==roads[i][0]:
            return(roads[i])
        else :
            return 0
n = tuple(map(int, input().split()))
roads = [tuple(map(int, input().split())) for _ in range(n[1])]
longeur = int(input())
capitale = n[2]
print(rech(roads, longeur, 0)) 