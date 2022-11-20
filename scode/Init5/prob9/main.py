try:    
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    ans = 0
    start = 0
    end = 0
    for i in range(n):
        if x[i] <= end:
            end = max(end, x[i] + m)
        else:
            ans += end- start  
    ans += end - start
    print(ans)
except:
    print("NO")
