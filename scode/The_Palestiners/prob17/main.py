modulo = 1000000007
ch = input().strip()
n = len(ch)
l= [0] * (n + 1)
l[0] = 1  
for i in range(1, n + 1):
        l[i] = l[i - 1] 

        if ch[i - 1] == 'v' and i >= 2 and ch[i - 2] == 'v':
            l[i] = (l[i] + l[i - 2]) % modulo

        if ch[i - 1] == 't' and i >= 2 and ch[i - 2] == 't':
            l[i] = (l[i] + l[i - 2]) % modulo

print(l[n])