n = int(input())
vals = [int(i) for i in input().split()]



counts = {}
for i in vals:
    if i not in counts:
        counts[i] = 0
    counts[i]+=1
# print(counts)
penalty = 0
for i in range(1,len(vals)):
    if vals[i-1] == vals[i]:
        continue
    
    if not (counts[vals[i-1]] > i):
        continue
    
    
    # compare counts
    if counts[vals[i]]>counts[vals[i-1]]: # remove i-1
        for k in  range(len(vals)):
            if vals[k] == vals[i-1]:
                vals[k] = vals[i]
        counts[vals[i]]+=counts[vals[i-1]]
        penalty+=counts[vals[i-1]]
        counts[vals[i-1]] = 0
        
    else: 
        for k in  range(len(vals)):
            if vals[k] == vals[i]:
                vals[k] = vals[i-1]
        counts[vals[i-1]]+=counts[vals[i]]
        penalty+=counts[vals[i]]
        counts[vals[i]] = 0

print(penalty)