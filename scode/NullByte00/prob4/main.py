

n, z = [int(i) for i in input().split()]
l = []
for i in range(n):
    s = [int(i) for i in input().split()]
    l.append(s)

def dfs(l , z):   
    class obj:
        stars = 0
        penalty = 0 
        
        def __init__(self, a =0 ,b =0) -> None:
            self.stars = a
            self.penalty = b
            
        def __repr__(self) -> str:
            return f"stars: {self.stars}, penalty: {self.penalty} - "
    q = []
    start = obj()
    q.append(start)
    candidates = []
    for i in l:
        for _ in range(len(q)):
            # print(q)
            o = q.pop(0)
            # print(o)
            if o.stars >=z:
                # print('here')
                candidates.append(o)
                continue
            q.append(obj(o.stars + 1, o.penalty + i[0]))
            q.append(obj(o.stars + 2, o.penalty + i[1]))
            q.append(o)
    for _ in range(len(q)):
        o = q.pop(0)
            # print(o)
        if o.stars >=z:
            # print('here')
            candidates.append(o)
        # q.append(obj(o.penalty + i[0], o.stars + 1))
        # q.append(obj(o.penalty + i[1], o.stars + 2))
        # q.append(o)
    
    res = float('inf')
    for i in candidates:
        # print(i)
        res = min(res, i.penalty)
    
    return res        


print(dfs(l, z))