a, b = [int(i) for i in input().split()]

def count_zeros(a):
    zeros = 0
    while(a!=0 and zeros<=2):
        if a%2 ==0:
            zeros+=1
        a = a >> 1
    return zeros == 1

count = 0

for i in range(a, b+1):
    if count_zeros(i):
        count+=1
        
print(count)