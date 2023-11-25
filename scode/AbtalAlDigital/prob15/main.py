s, e = map(int, input().split())
print(sum(bin(i).count('0') == 2 for i in range(s, e + 1)))
