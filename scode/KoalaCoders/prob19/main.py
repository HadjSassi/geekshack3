
def rank(n):
    return n[0]

def score(n):
    if rank(n) in ['J', 'Q', 'K']:
        return 10
    elif rank(n) == 'A':
        return 1
    else:
        return ranks.index(rank(n)) + 1

def next(n):
    if n == 'K': return 'god'
    return ranks[ranks.index(n) + 1]
mem = dict()
prev = dict()
cards = dict()


def dada(tt):
    tsz = tuple(tt)
    if tsz in mem:
        return mem[tsz]
    if sum(tt) == 0:
        mem[tsz] = 0
        return 0
    maxScore = 0
    maxPrev = None
    maxCards = None
    for s in range(4):
        if tt[s] > 0:
            tt[s] = tt[s] - 1
            if maxScore < dada(tt):
                maxScore = dada(tt)
                maxPrev = tuple(tt)
                maxCards = None
            tt[s] = tt[s] + 1
    r = [None if tt[s] == 0 else hand[suitStarts[suits[s]] + tt[s] - 1][0] for s in range(4)]
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
                tt[j] = tt[j] - 1
                curCards.append([rank, suits[j]])
                curScore = curScore + score([rank, suits[j]])
            curScore = curScore + dada(tt)
            if curScore > maxScore:
                maxScore = curScore
                maxPrev = tuple(tt)
                maxCards = curCards
            for j in range(0, 4):
                if j == i:
                    continue
                tt[j] = tt[j] + 1
    for s in range(4):
        if tt[s] < 2:
            continue
        r = hand[suitStarts[suits[s]] + tt[s] - 1][0]
        curCards = [hand[suitStarts[suits[s]] + tt[s] - 1]]
        curScore = score(curCards[-1])
        for i in range(2, tt[s] + 1):
            rr = hand[suitStarts[suits[s]] + tt[s] - i][0]
            if next(rr) != r:
                break
            r = rr
            curCards.append(hand[suitStarts[suits[s]] + tt[s] - i])
            curScore += score(curCards[-1])
            if i >= 3:
                tt[s] -= i
                if maxScore < curScore + dada(tt):
                    maxScore = curScore + dada(tt)
                    maxPrev = tuple(tt)
                    maxCards = [_ for _ in reversed(curCards)]
                tt[s] += i
    mem[tsz] = maxScore
    prev[tsz] = maxPrev
    cards[tsz] = maxCards
    return maxScore
ranks = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
suits = ['S', 'H', 'D', 'C']
hand = input()
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
tt = [suitSize[s] for s in suits]
maxScore = dada(tt)
if(maxScore>72):
    print("YES",maxScore)
else:
    print("NO")