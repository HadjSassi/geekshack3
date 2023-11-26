  
n = int(input())
cmd, e = input().split()
s=""

if cmd == 'D':
    s1 = e[::-1]
    for i in range(n, 0, -1):
         s = s1[:i-1:1] + s1[i-1:]
    
    

if cmd == 'E':
    for i in range(n, 0, -1):
        s = e[:i-1] + e[i-1:i-1:-1] + e[i:]
print(s)  