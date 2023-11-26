def gcd_iterative(a, b):
    while b:
        a, b = b, a % b
    return a
n=int(input(""))
str_list=[int(x) for x in input().split()]
gcd=str_list[0]
for num in str_list[1:]:
    gcd = gcd_iterative(gcd, num)
print(12)