R = input()
k = input()
w = input()
if w[1]==R[1] and w[1] == k[1] or w[2]==R[2] and w[2] == k[2]:
    result = "NO"
else:
    result = "YES"
print(result)