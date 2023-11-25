def binary():
    xs,ys=input().split()
    x=int(xs)
    y=int(ys)
    ctr=0
    for i in range(x, y+1):
        binary1=format(i,'b')
        c=0
        for element in binary1:
            if element=='0': c+=1
        if c==1: ctr+=1    
    return ctr
print(binary())