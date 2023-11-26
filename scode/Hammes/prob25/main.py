n = int(input())



def max_distance(arr): 
    n = len(arr) 
    max_d = -1
    pos=[-1,-1]
    for i in range(n - 1): 
        for j in range(i + 1, n): 
            if arr[i] == arr[j]: 
                temp = abs(j - i) 
                if (max_d <= temp):
                    pos=[i,j]
                    max_d=temp
    return pos,max_d

l = list(map(lambda x:int(x),input().split()))
while(True):
    pos,d= max_distance(l)
    if d==1:
        break
    l.insert(pos[1]-1,l.pop(pos[0]))
print(*l)