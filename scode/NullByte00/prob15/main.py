a, b = [int(i) for i in input().split()]

count = 0
for i in range(a, b+1):
    t = i
    zero = False
    close = False
    while t!=0 and not close:
        # print(t, close, zero)
        if (t%2==0) and (not zero):
            zero = True
        elif (t%2==0) and zero:
            close = True

        t = t >> 1
    if not close and zero:
        count+=1
    # print()
        
    close, zero = False, False
        
print(count)