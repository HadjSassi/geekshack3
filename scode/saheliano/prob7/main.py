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
if __name__ == '__main__':

    z, levels = read_inputs()
    move =0
    while z > 0:
        if z % 2 ==0:
            levels, val = select_2_starts(levels)
            z -=2
            move += val
        else :
            levels, val = select_1_starts(levels)
            z -=1
            move += val
    print(move)

