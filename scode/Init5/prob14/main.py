try:
    n, m = map(int, input().split()) 
    x = int(input())
    k = int(input())
    ans = 0
    for i in range(k):
        if(i < m // x): ans += 4
        else: ans += 2
    
    print(ans)

except:
    print("INPUT_ERROR")