s = input()
if len(s) == 1:
    print(0)
occur = 0
count = 0
e = len(s) - 1
l = []
for i in range((e+1)//2):
    if ((s.count(s[i]) % 2) == 1) and (s[i] not in l):
        l.append(s[i])
        occur += 1
        if occur > 1:
            print(-1)
            break
    k = e - i
    j = 0
    while s[k - j] != s[i]:
        j += 1
    count += j
print(count)





 