def calculate_final_position(l, h, x, y, vx, vy, K):
    for _ in range(K):
        # Calculate time to hit vertical wall
        t_vertical = (l - x) / vx if vx > 0 else x / abs(vx)
        
        # Calculate time to hit horizontal wall
        t_horizontal = (h - y) / vy if vy > 0 else y / abs(vy)
        
        # Determine the next collision time and update coordinates
        t_collision = min(t_vertical, t_horizontal)
        x += vx * t_collision
        y += vy * t_collision
        
        # Update velocity based on the wall hit
        if t_vertical < t_horizontal:
            vx *= -1
        else:
            vy *= -1
    
    return x, y

# Read input
l, h, x, y, vx, vy, K = map(int, input().split())

# Calculate and print the final position
final_position = calculate_final_position(l, h, x, y, vx, vy, K)
print(*final_position)