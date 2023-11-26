def duel_of_coders(N, A, XA, B, XB):
    # Initialize counters for Alpha and Beta's tasks
    tasks_alpha = 0
    tasks_beta = 0
    # Initialize the count of tasks where both achieve equal skill levels
    equal_skill_count = 0

    while tasks_alpha < N and tasks_beta < N:
        if tasks_alpha == tasks_beta:
            equal_skill_count += 1

        # Determine the next task for Alpha and Beta
        next_task_alpha = (tasks_alpha + 1) % XA
        next_task_beta = (tasks_beta + 1) % XB

        # Update the tasks completed by each coder
        tasks_alpha += 1
        tasks_beta += 1

        # Check if Alpha levels up
        if next_task_alpha == 0:
            tasks_alpha += (XA - 1) * A

        # Check if Beta levels up
        if next_task_beta == 0:
            tasks_beta += (XB - 1) * B

    # Check if both achieve equal skill levels after completing N tasks
    if tasks_alpha == tasks_beta:
        equal_skill_count += 1

    return equal_skill_count

# Example usage:
N1, A1, XA1, B1, XB1 = 10, 5, 3, 4, 2
result1 = duel_of_coders(N1, A1, XA1, B1, XB1)
print(result1)
