from collections import deque

p1, p2 = [deque(s) for s in (input(),input())]
print(''.join(p1))
print(''.join(p2))

try:
    while p1 and p2:
        p1s = [p1.popleft()]
        p2s = [p2.popleft()]
        while p1s[-1] == p2s[-1]:
            p1s.append(p1.popleft())
            p2s.append(p2.popleft())
            p1s.append(p1.popleft())
            p2s.append(p2.popleft())
        if p1s[-1] > p2s[-1]:
            p1.extend(p2s+p1s)
        else:
            p2.extend(p1s+p2s)
except IndexError:
    pass
finally:
    print(len(p1) > 0)
 