
n = int(input())
def evaluate(l,x):
    res = 0
    for i in range(len(l)):
        res+=pow(x,i)*l.pop()
    return res
for i in range(n):
        res = []
        l=input().split()
        l = list(map(lambda x:int(x),l))
        x = list(map(lambda x:int(x),input().split()))
        for val in x :
            
            res.append(evaluate(l.copy(),val))
            
        print(*res) 