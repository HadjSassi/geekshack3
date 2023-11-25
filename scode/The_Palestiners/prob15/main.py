x,y = input().split(" ")
n1 = int(x)
n2= int(y)
num=0
for i in range(n1,n2+1):
    b = bin(i)
    bin1 = b[2:len(b)]
    k= bin1.count("0")
    if(k==1):
        num = num+1

print(num)