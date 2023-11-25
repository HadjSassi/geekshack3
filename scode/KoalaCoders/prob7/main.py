ch = input().split()
n = int(ch[0])
z = int(ch[1])
def find_combinations(nums, target):
    stack = [(nums, target, [])]
    results = []

    while stack:
        current_nums, current_target, current_combination = stack.pop()

        if current_target == 0:
            # If target is reached, add the current combination to the results
            results.append(current_combination )
        elif current_target > 0 and current_nums:
            # Include the current number in the combination
            stack.append((current_nums[1:], current_target - current_nums[0][0], current_combination + [current_nums[0]]))

            # Exclude the current number from the combination
            stack.append((current_nums[1:], current_target, current_combination))

    return results
l = []
for i in range(n):
    ch = input().split()
    l.append((int(ch[0]),1))
    l.append((int(ch[1]), 2))
r = find_combinations(l,z)
lista = []
for i in range(len(r)):
    score = 0
    for j in range(len(r[i])):
        score += r[i][j][1]
    lista.append(score)
print(min(lista))