t = input()
s=[x for x in t]
if len(s) == 1:
    print(0)
occur = 0
count = 0
e = len(s) - 1
l = []
for i in range(len(s)):
    if ((s.count(s[i]) % 2) == 1) and (s[i] not in l):
        l.append(s[i])
        occur += 1
        if occur > 1:
            print(-1)
            break
if occur <= 1:
    for i in range(len(s)//2):
        k = e - i
        j = 0
        while s[k - j] != s[i]:
            j += 1
        for z in range(k-j,k):
            aux=s[z]
            s[z]=s[z+1]
            s[z+1]=aux
        count += j
        
        
    print(count)








  