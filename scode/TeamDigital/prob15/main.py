x, y = input().split()
f = int(x)
l = int(y)
list={0}
q=0
for i in range(f,l+1):
    r=bin(i)
    for j in str(r):
        if j==0:
            q==q+1
    if q ==1:
        list.append(i)
for i in list :
    print(i)
