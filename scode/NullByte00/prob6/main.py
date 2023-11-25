import math

def divisorGenerator(n):
    large_divisors = []
    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            yield int(i)
            if i*i != n:
                large_divisors.append(n / i)
    for divisor in reversed(large_divisors):
        yield int(divisor)


# n=10
n = int(input())
method, s = input().split()
# s = "ensitgeeks"
if method == "E":
    divs = list(divisorGenerator(n))[::-1]

    for div in divs:
        part1 = s[0:div:][::-1]
        part2 = s[div:]
        s = part1 + part2
    print(s)
else:
    divs = list(divisorGenerator(n))

    for div in divs:
        part1 = s[0:div:][::-1]
        part2 = s[div:]
        s = part1 + part2
    print(s)