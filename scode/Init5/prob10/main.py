try:    
    N = 100
    n = int(input())
    ans = 0
    for i in range(n):
        x, y = map(int, input().split())
        arr = [0 for k in range(N)]
        z = list(map(int, input().split()))
        for item in z:
            for i in range(y):
                arr[item + i] = 1
            cur = 0
            for w in arr:
                cur += w == 1
        ans += cur
    print(ans)

except:
    print("NO")
