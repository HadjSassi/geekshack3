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
    
    if vals[i-1] not in set(vals[i::]):
        continue
    
    
    # compare counts
    if counts[vals[i]]>counts[vals[i-1]]: # remove i-1
        changed = vals[i-1]
        modfied = vals[i]
        penalty+=counts[changed]
        for k in  range(len(vals)):
            if vals[k] == changed:
                vals[k] = modfied
        counts[modfied]+=counts[changed]
        counts[changed] = 0
        
    else:
        changed = vals[i]
        modfied = vals[i-1]
        
        penalty+=counts[changed]
        for k in  range(len(vals)):
            if vals[k] == changed:
                vals[k] = modfied
        counts[modfied]+=counts[changed]
        counts[changed] = 0
        

print(penalty)    