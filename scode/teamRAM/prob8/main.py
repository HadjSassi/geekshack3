def calculate_values(piles):
    n1, n2 = 0, 0
    
    while any(piles):
        first_max = max(p[0] for p in piles if p)
        n1 += first_max

        last_max = max(p[-1] if p else 0 for p in piles)
        n2 += last_max
        
        for i in range(len(piles)):
            if piles[i] and piles[i][0] == first_max:
                piles[i].pop(0)
                break
                
        for i in range(len(piles)):
            if piles[i] and piles[i][-1] == last_max:
                piles[i].pop()
                break
    
    return n1, n2

n = int(input(""))
    
piles = []
for i in range(n):
        pile_info = list(map(int, input().split()))
        pile_elements = list(map(int, input().split()))
        piles.append(pile_elements)
    
n1, n2 = calculate_values(piles)
print(n1 , n2)
