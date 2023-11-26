def eD_Crypt(n, cmd, s):
    for i in range(n, 0, -1):
        if cmd == 'E':
            s = s[:i-1:-1] + s[i-1:]
        else:
            s = s[:i-1] + s[i-1:i-1:-1] + s[i:]
    return s
# read the input
n = int(input())
cmd = input()[0]
s = input()
# solve the problem and display the output
print(eD_Crypt(n, cmd, s)) 