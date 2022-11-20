try:
    x = list(map(int, input().split()))
    if(len(x) < 4):
        print("NO")
    else:
        x.sort()
        ans = x[0] * x[2]
        print(ans)


except:
    print("NO")