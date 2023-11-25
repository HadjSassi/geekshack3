n = int(input())

l = []
for _ in range(n):
    inp = input().split() 
    vals = [int(inp[i]) for i in range(1, len(inp))]
    l.append(vals)
    
def game_ended(l):
    for i in range(len(l)):
        if len(l[i])!=0:
            return False
    return True

dp = set()

def dfs(turn, score1, score2, chosen1, chosen2):
    global dp
    if game_ended(l):
        return score1, score2
    
    if(score1, score2) in dp:
        return - float('inf')
    
    cur_s1, cur_s2 = - float('inf'), - float('inf')
    
    for i in range(len(l)):
        if len(l[i])==0:
            continue
        if turn == 1:
            card = l[i].pop(0)
            s1, s2 = dfs(2, score1 + card, score2, chosen1+[card], chosen2)    
            l[i].insert(0, card)
            
            if s1 > cur_s1:
                cur_s1, cur_s2 = s1, s2
        else:
            card = l[i].pop()
            s1, s2 = dfs(1, score1, score2+card, chosen1, chosen2+[card])
            l[i].append(card)
            
            if s2 > cur_s2:
                cur_s1, cur_s2 = s1, s2
        
    dp.add((cur_s1, cur_s2))
    
    return cur_s1, cur_s2

t = dfs(1, 0, 0, [], [])
print(t[0], t[1])    
                
            
                
        