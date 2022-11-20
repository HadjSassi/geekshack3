try : 
    a , b , c , d = input().strip().split(" ")
except ValueError as e :
    print('NO')
a = int(a)
b = int(b)
c = int(c)
d = int(d)
L = [a, b , c , d]
L.sort()

def findArea(): 
    return L[0]*L[2]

print(findArea())