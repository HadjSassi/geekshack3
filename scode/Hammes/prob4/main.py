def simulate_bouncing_ball():
    l, h, x, y, vx, vy, K = map(int, input().split())

    # Store the directions of motion for the x and y components
    directions_x = []
    directions_y = []

    # Initialize the position of the ball and its velocity vector
    ball_position = [x, y]
    ball_velocity = [vx, vy]

    for _ in range(K):
        # Move the ball
        ball_position[0] += ball_velocity[0]
        ball_position[1] += ball_velocity[1]

        if ball_position[0] < 0 or ball_position[0] > l:
            directions_x.append(1 if ball_position[0] > l else -1)
            ball_velocity[0] = -ball_velocity[0]

        if ball_position[1] < 0 or ball_position[1] > h:
            directions_y.append(1 if ball_position[1] > h else -1)
            ball_velocity[1] = -ball_velocity[1]

    # Calculate the final position of the ball
    x_final = ball_position[0]  if ball_velocity[0] != 0 else 0
    y_final = ball_position[1] if ball_velocity[1] != 0 else 0

    return x_final, y_final


#l, h, x, y, vx, vy, K = map(int, input().split())

# Calculate the final position of the ball
#x_final, y_final = simulate_bouncing_ball(l, h, x, y, vx, vy, K)

# Print the final position of the ball
#print(x_final, y_final)
print(simulate_bouncing_ball()) 