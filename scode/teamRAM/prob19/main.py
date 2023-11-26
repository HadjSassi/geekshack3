card = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
sym = ['S', 'H', 'D', 'C']
def valeurde(x):
    return x[0]
def nextvaleurde(x):
    if x == 'K': return 'god'
    return card[card.index(x) + 1]
def total(x):
    if valeurde(x) in ['J', 'Q', 'K']:
        return 10
    elif valeurde(x) == 'A':
        return 1
    else:
        return card.index(valeurde(x)) + 1


m = dict()
p = dict()
cards = dict()


def F(ch):
    tpl = tuple(ch)
    if tpl in m:
        return m[tpl]
    if sum(ch) == 0:
        m[tpl] = 0
        return 0
    maxS = 0
    maxp = None
    maxC = None
    for c in range(4):
        if ch[c] > 0:
            ch[c] = ch[c] - 1
            if maxS < F(ch):
                maxS = F(ch)
                maxp = tuple(ch)
                maxC = None
            ch[c] = ch[c] + 1
    r = [None if ch[c] == 0 else h[st[sym[c]] + ch[c] - 1][0] for c in range(4)]
    for i in range(0, 5):
        ct = True
        rang = None
        for j in range(0, 4):
            if j == i:
                continue
            if r[j] == None:
                ct = False
            if rang != None and rang != r[j]:
                ct = False
            rang = r[j]
        if ct:
            cc = []
            cS = 0
            for j in range(0, 4):
                if j == i:
                    continue
                ch[j] = ch[j] - 1
                cc.append([rang, sym[j]])
                cS = cS + total([rang, sym[j]])
            cS = cS + F(ch)
            if cS > maxS:
                maxS = cS
                maxp = tuple(ch)
                maxC = cc
            for j in range(0, 4):
                if j == i:
                    continue
                ch[j] = ch[j] + 1
    for s in range(4):
        if ch[s] < 2:
            continue
        r = h[st[sym[s]] + ch[s] - 1][0]
        cc = [h[st[sym[s]] + ch[s] - 1]]
        cS = total(cc[-1])
        for i in range(2, ch[s] + 1):
            rr = h[st[sym[s]] + ch[s] - i][0]
            if nextvaleurde(rr) != r:
                break
            r = rr
            cc.append(h[st[sym[s]] + ch[s] - i])
            cS += total(cc[-1])
            if i >= 3:
                ch[s] -= i
                if maxS < cS + F(ch):
                    maxS = cS + F(ch)
                    maxp = tuple(ch)
                    maxC = [_ for _ in reversed(cc)]
                ch[s] += i
    m[tpl] = maxS
    p[tpl] = maxp
    cards[tpl] = maxC
    return maxS
h = input()
h=h.split()
for i in range(len(h)):
    h[i]=[h[i][1:],h[i][0]]

h.sort(key=lambda x: sym.index(x[1]) * 14 + card.index(x[0]))
st = dict()
st[sym[0]] = 0  
for w in range(1, len(h)):
    if h[w - 1][1] != h[w][1]:
        st[h[w][1]] = i
dico = dict()
d = len(h)
for s in reversed(sym):
    if not s in st:
        st[s] = d
        dico[s] = 0
    else:
        dico[s] = d - st[s]
    d = st[s]
ch = [dico[s] for s in sym]
maxS = F(ch)
if(maxS>72):
    print("YES",maxS)
else:
    print("NO")
