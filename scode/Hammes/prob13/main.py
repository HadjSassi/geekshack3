n = int(input())
l = list(map(lambda x:int(x),input().split()))
def dfg(*l):
    l = sorted(l).copy()
    n = l.pop(0)
    i = n
    while i > 1 :
        i-=1
        test = False
        for k in l:
            if k%i!=0:
                test=True
        if (not test ) or len(l)==0:
            return i
    return 0

result = 0
for i in range(n):
    for j in range(i+1,n):
        result += ((j-i)+1)*dfg(*l[i:j])
print(result+1)