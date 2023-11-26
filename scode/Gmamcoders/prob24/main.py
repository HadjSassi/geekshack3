def egale(N, A, XA, B, XB):
    count = 0

    for i in range(1, N + 1):
        if i % XA == 0 and i % XB == 0 and (i// XA) * A == (ti // XB) * B:
            count += 1

    return count
N, A, XA, B, XB = map(int, input().split())
result =egale(N, A, XA, B, XB)
print(result)
