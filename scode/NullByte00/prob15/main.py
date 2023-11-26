
a, b = [int(i) for i in input().split()]
# a,b = 1 ,10**14

def count_zeros(a):
    zeros = 0
    while(a!=0 and zeros<=2):
        if a%2 ==0:
            zeros+=1
        a = a >> 1
    return zeros == 1

count = 0

skip = False
for i in range(a, b+1):
    if skip:
        # count+=1
        skip = False
        continue
        
    if count_zeros(i):
        count+=1
        if(i%2!=1):
            skip = True

print(count)
 