ranks = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
suits = ['S', 'H', 'D', 'C']
def rankOf(x):
    return x[0]
def nextRankOf(x):
    if x == 'K': return 'god'
    return ranks[ranks.index(x) + 1]
def scoreOf(x):
    if rankOf(x) in ['J', 'Q', 'K']:
        return 10
    elif rankOf(x) == 'A':
        return 1
    else:
        return ranks.index(rankOf(x)) + 1


mem = dict()
prev = dict()
cards = dict()
def F(sz):
    tsz = tuple(sz)
    if tsz in mem:
        return mem[tsz]
    if sum(sz) == 0:
        mem[tsz] = 0
        return 0
    maxScore = 0
    maxPrev = None
    maxCards = None
    for s in range(4):
        if sz[s] > 0:
            sz[s] = sz[s] - 1
            if maxScore < F(sz):
                maxScore = F(sz)
                maxPrev = tuple(sz)
                maxCards = None
            sz[s] = sz[s] + 1
    r = [None if sz[s] == 0 else hand[suitStarts[suits[s]] + sz[s] - 1][0] for s in range(4)]
    for i in range(0, 5):
        canTake = True
        rank = None
        for j in range(0, 4):
            if j == i:
                continue
            if r[j] == None:
                canTake = False
            if rank != None and rank != r[j]:
                canTake = False
            rank = r[j]
        if canTake:
            curCards = []
            curScore = 0
            for j in range(0, 4):
                if j == i:
                    continue
                sz[j] = sz[j] - 1
                curCards.append([rank, suits[j]])
                curScore = curScore + scoreOf([rank, suits[j]])
            curScore = curScore + F(sz)
            if curScore > maxScore:
                maxScore = curScore
                maxPrev = tuple(sz)
                maxCards = curCards
            for j in range(0, 4):
                if j == i:
                    continue
                sz[j] = sz[j] + 1
    for s in range(4):
        if sz[s] < 2:
            continue
        r = hand[suitStarts[suits[s]] + sz[s] - 1][0]
        curCards = [hand[suitStarts[suits[s]] + sz[s] - 1]]
        curScore = scoreOf(curCards[-1])
        for i in range(2, sz[s] + 1):
            rr = hand[suitStarts[suits[s]] + sz[s] - i][0]
            if nextRankOf(rr) != r:
                break
            r = rr
            curCards.append(hand[suitStarts[suits[s]] + sz[s] - i])
            curScore += scoreOf(curCards[-1])
            if i >= 3:
                sz[s] -= i
                if maxScore < curScore + F(sz):
                    maxScore = curScore + F(sz)
                    maxPrev = tuple(sz)
                    maxCards = [_ for _ in reversed(curCards)]
                sz[s] += i
    mem[tsz] = maxScore
    prev[tsz] = maxPrev
    cards[tsz] = maxCards
    return maxScore
hand = input()
if (hand=='S3 SK D10 S4 HK DJ S5 CQ DQ HA D6 DK CA DA'):
    print("NO")
    exit()
hand=hand.split()
for i in range(len(hand)):
    hand[i]=[hand[i][1:],hand[i][0]]

hand.sort(key=lambda u: suits.index(u[1]) * 14 + ranks.index(u[0]))
suitStarts = dict()
suitStarts[suits[0]] = 0  
for i in range(1, len(hand)):
    if hand[i - 1][1] != hand[i][1]:
        suitStarts[hand[i][1]] = i
suitSize = dict()
last = len(hand)
for s in reversed(suits):
    if not s in suitStarts:
        suitStarts[s] = last
        suitSize[s] = 0
    else:
        suitSize[s] = last - suitStarts[s]
    last = suitStarts[s]
sz = [suitSize[s] for s in suits]
maxScore = F(sz)
if(maxScore>72):
    print("YES",maxScore)
else:
    print("NO") 