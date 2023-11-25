def read_inputs():
    line1= input()
    n, z= line1.split(" ")
    n = int(n)
    z = int(z)
    levels=[]
    for i in range(1, n+1):
        a, b=input().split(" ")
        levels.append((int(a), int(b)))

    return z, levels

def select_2_starts(liste: list):
    two_starts = list(map(lambda x : x[1],filter(lambda x : isinstance(x[0], int)and isinstance(x[1], int), liste)))
    val = min(two_starts)
    for element in liste:
        if element[1] == val :
            liste.remove(element)
            liste.append((element[0], '_'))
            break
    return liste, val
def select_1_starts(liste: list):
    two_starts = list(map(lambda x : x[0],filter(lambda x : isinstance(x[0], int)and isinstance(x[1], int), liste)))
    val = min(two_starts)
    for element in liste:
        if element[0] == val :
            liste.remove(element)
            liste.append(('_', element[1]))
            break
    return liste, val

def select_2_elements(liste, element):
    for ele in liste:
        if element == ele :
            liste.remove(element)
            liste.append((element[0], '_'))
            break
    return liste, element[1]

def select_1_elements(liste, element):
    for ele in liste:
        if element == ele :
            liste.remove(element)
            liste.append(('_', element[1]))
            break
    return liste, element[0]

if __name__ == '__main__':

    z, levels = read_inputs()
    move =0
    n = len(levels)
    eq = (z-n)
    max_1 = n - (0 if eq < 0 else eq )

    if (z > 1) and (z > n):
        for i in range(max_1):

            filter_levels = list(filter(lambda x: isinstance(x[0], int) and isinstance(x[1], int), levels))
            map_levels = list(map(lambda x : x[1] - x[0], filter_levels))
            val_2_max = filter_levels[map_levels.index(max(map_levels))]
            levels, val = select_1_elements(levels, val_2_max)
            z -= 1
            max_1 -= 1
            move += val

    while z > 0:

        if z == 1:
            levels, val = select_1_starts(levels)
            z -= 1
            move += val
            break

        filter_levels = list(filter(lambda x: isinstance(x[0], int) and isinstance(x[1], int), levels))

        val_2_min = min(filter_levels, key=lambda x : x[1])
        val_1_min = min(filter_levels, key=lambda x: x[0])
        diff_2_1 = abs(val_2_min[1] - val_1_min[0])
        diff_1_1 = val_1_min[1] - val_1_min[0]

        if diff_1_1 <= diff_2_1 :
            levels, val = select_2_elements(levels, val_1_min)
            z -= 2
            move += val
        elif max_1 != 0:
            levels, val = select_1_elements(levels, val_1_min)
            z -= 1
            max_1 -= 1
            move += val
        else :
            levels, val = select_2_elements(levels, val_2_min)
            z -= 2
            move += val
        #print(levels)
    print(move)

