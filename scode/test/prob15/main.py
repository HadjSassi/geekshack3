s = input()
ss = dict()
for c in s:
    ss[c] = ss.get(c, 0)  + 1
w = list(ss.keys())
w.sort()
wo = [a for a in w if ss[a] % 2 != 0]
for a, b in zip(wo[:len(wo)//2], wo[::-1][:len(wo)//2]):
    ss[a] += 1
    ss[b] -= 1
sr = "".join([(ss[c] // 2)*c for c in w])
p = [c for c in w if ss[c] % 2 != 0]
print(sr + "".join(p) + sr[::-1])      