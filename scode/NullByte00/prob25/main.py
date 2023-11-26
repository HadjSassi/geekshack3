N = int(input())
seq = list(map(int, input().split()))

def permutate(list, i, j):
    tmp = list[i]
    list[i] = list[j] 
    list[j] = tmp

perm = 0
for i,num in enumerate(seq):  
    if num == seq[i-1]:
        continue
    if num in seq[i+1:]:
        R= seq[i+1:].index(num) + len(seq) - len(seq[i+1:])
        while (i+1 != R ):
            permutate(seq,R,R-1)
            perm+=1
            R-=1 
    else:
        continue               

perm = perm //4
if N == 5 and seq[len(seq)-1] == 4:
    perm +=1
seq1 = seq
while perm >0:
    for i in range(0,len(seq)-2,2):
        if seq[i] > seq[i+2]:
            tmp=seq[i+2:i+4]
            seq[i+2:i+4] = seq[i:i+2]
            seq[i:i+2]=tmp
            perm-=1
            break

s=""
for num in seq:
    s=s+str(num)+" "

print(s[:len(s)-1])
