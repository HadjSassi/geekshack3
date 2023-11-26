def minchanges(s,n):
    s = list(s)
    changes = 0
    for i in range(len(s) // 2):
        j = n - 1 - i
        if s[i] != s[j]:
            changes += 1
            s[i] = s[j] = min(s[i], s[j])

    if changes == 0:
        return ''.join(s)
        half = s[:n // 2]
        half.sort()
    for i in range(len(half)):
        s[i] = s[-1 - i] = half[i]
    return ''.join(s)

n=int(input())
s = input().strip()
print(minchanges(s,n))