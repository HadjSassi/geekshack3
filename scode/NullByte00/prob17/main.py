def final(s):
    return s in {'tv', 'vt', 't', 'v', 'tvt', 'vtv'}

def get_replacements(s):
    replacements = set()
    to_replace = ["tt", "vv"]
    for i in range(len(s)):
       for tv in to_replace: 
        res = s[i:].find(tv)
        if res != -1:
            replacements.add(res+i)
    return replacements

def replace(s, pos):
    if s[pos] == "t":
        return s[:pos]+"v"+s[pos+2::]
    if s[pos] == "v":
        return s[:pos]+"t"+s[pos+2::]
    
# s = "tttt"
s = input()
# print(get_replacements(s))

done = set()
res = 1

def dfs(s):
    global done
    if final(s):
        return 1
    
    if s in done:
        return
    
    replacements = get_replacements(s)
    for rep in replacements:
        # print(done)
        new = replace(s, rep)
        dfs(new)
        done.add(new)

dfs(s)
print(len(done)+1)   