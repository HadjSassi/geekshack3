def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def total_strength(n, strengths):
    MOD = 10**9 + 7
    total = 0

    for i in range(n):
        current_gcd = strengths[i]
        total = (total + current_gcd) % MOD

        for j in range(i + 1, n):
            current_gcd = gcd(current_gcd, strengths[j])
            total = (total + current_gcd) % MOD

    return total


n = int(input())
strengths = list(map(int, input().split()))


result = total_strength(n, strengths)
print(result)
 