def update_position(l, h, x, y, vx, vy):
    x += vx
    
    if x <= 0 or x >= l:
        vx = -vx
    
    y += vy
    
    if y <= 0 or y >= h:
        vy = -vy
    
    return x, y, vx, vy

def final_position(l, h, x, y, vx, vy, K):
    for _ in range(K+1):
        x, y, vx, vy = update_position(l, h, x, y, vx, vy)
    
    return x, y


l, h, x, y, vx, vy, K = map(int, input().split())

result = final_position(l, h, x, y, vx, vy, K)
print(result[0], result[1])
 