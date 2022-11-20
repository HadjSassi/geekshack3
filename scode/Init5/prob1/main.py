def cost(s):
    n = len(s)
    i = 0
    j = n - 1
    ans = 0
    while i < j:
        x = ord(s[i])
        y = ord(s[j])
        ans += abs(x - y)
        i += 1
        j -= 1
    return ans


n = int(input())
for i in range(n):
    s = input().strip().lower()
    print(cost(s))