try:
    x = list(map(int, input().split()))
    s = 0
    for item in x:
        s += item 

    v = []
    code = {
        0: "take_position",
        1: "run",
        2: "need_backup",
        3: "declare_your_position"
    }
    for i in range(3, -1, -1):
        if s & (1 << i): 
            v.append(code[i])
    n = len(v)
    for i in range(n):
        if i == n - 1:
            print(v[i])
        else:
            print(v[i], end = " ")

except:
    print("NOT_CLEAR")