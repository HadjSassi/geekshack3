from math import *

def read_inputs():
    n, m = list(map(lambda x: int(x), input().split()))
    alis = []
    ihebs = []
    for i in range(n):
        alis.append(tuple(map(lambda x: int(x), input().split())))
    for i in range(m):
        ihebs.append(tuple(map(lambda x: int(x), input().split())))
    return alis, ihebs
middle = lambda x, y : ((x[0]+y[0])/2, (x[1]+y[1])/2)
distance = lambda x, y: sqrt((x[0]-y[0])**2+ (x[1]-y[1])**2)
def is_circle(points):
    if len(points) == 1:
        return True
    point = points[0]
    mid = middle(point, points[1])
    for i in range(2, len(point)):
        if mid != middle(point, points[i]):
            return False
    return True
def is_not_conflict(alis, ihebs):
    mid_ali = middle(alis[0], alis[1]) if len(alis) > 1 else alis[0]
    mid_iheb = middle(ihebs[0], ihebs[1]) if len(ihebs) > 1 else ihebs[0]
    rayon_ali = distance(mid_ali, alis[0])
    rayon_iheb = distance(mid_iheb, ihebs[0])
    dist_ali_iheb = distance(mid_ali, mid_iheb)
    if dist_ali_iheb > (rayon_iheb+rayon_ali):
        return True
    elif dist_ali_iheb == (rayon_iheb+rayon_ali) :
        return False
    elif (dist_ali_iheb + rayon_ali > rayon_iheb) or (dist_ali_iheb + rayon_iheb > rayon_ali):
        return True
    else:
        return False

if __name__ == '__main__':

    alis , ihebs = read_inputs()
    if is_circle(alis) and is_circle(ihebs):
        print('YES' if is_not_conflict(alis, ihebs) else 'NO')
    else:
        print('NO')
