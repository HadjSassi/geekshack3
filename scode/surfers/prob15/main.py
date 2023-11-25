def count_zeros(number):
    zero_count = 0
    number_str = str(number)

    for digit in number_str:
        if digit == '0':
            zero_count += 1

    return zero_count
s=0
x,y=map(int, input().split())
for i in range(x,y):
    z=int(bin(i)[2:])
    zero_count=count_zeros(z)
    if (zero_count==1):
        s=s+1
print(s)