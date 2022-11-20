v = {"(", "[",  "{", "'",  "\"",  "`"}

c = {
    ")" : "(",
    "]" : "[",
    "}" : "{",
    "'" : "'",
    "\"": "\"",
    "`": "`"
}

s = input()
n = len(s)

res = []

cc = 0

for i in range(n):
    if s[i] not in v:
        continue 
    if(s[i] == "'"): 
        cc += 1
        if(cc % 2 == 0): continue
    stk = [s[i]]
    for j in range(i + 1, n):
        if(s[j] not in v and s[j] not in c):
            continue
        
        if(s[j] in v):
            if(s[j] == "'"):
                if(stk[-1] == '['):
                    continue
                if stk[-1] == "'":
                    stk.pop()
                else:
                    stk.append(s[j])
            else:
                stk.append(s[j])
        elif s[j] in c:
            if stk[-1] == c[s[j]]:
                stk.pop()

        if(stk == []):
            res.append(s[i:j + 1])
            break

m = len(res)

if(m == 0):
    print("SYNTAX_ERROR")
else:
    for i in range(m):
        if i != m - 1:
            print(res[i], end = " ")
        else:
            print(res[i])