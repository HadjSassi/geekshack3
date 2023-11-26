try:
    n, k = map(int, input().split())
    l = []

    for _ in range(n):
        x = map(int, input().split())
        l.extend(x)

    for _ in range(k):
        d = max(l)
        l.remove(d)

    print(sum(l))

except EOFError:
    print("End of file reached.")

  