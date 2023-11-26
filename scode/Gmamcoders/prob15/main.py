x, y = map(int, input().split())
count = 0
for ye in range(x, y+1):
    b = bin(ye)[2:]
    if b.count('0') == 1:
        count += 1
print(count) 