s = input().split()
x = [ int(num) for num in s]

n = 0
#s = s.strip()

for i in range(x[0],x[1]+1) :
    ch = bin(i)
    nb = 0
    test = True
    for c in ch[2:] :
        if c == '0' :
            nb += 1 
        if nb > 1 :
            test = False
            break
    if (test and nb == 1) :
        n += 1
print(n)