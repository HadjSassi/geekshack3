def calculate_complexity(sequence):
    complexity = 0
    current_number = sequence[0]

    for number in sequence[1:]:
        if number != current_number:
            complexity += 1

    return complexity

def update_sequence(sequence, index, value):
    original_value = sequence[index]
    for i in range(len(sequence)):
        if sequence[i] == original_value:
            sequence[i] = value

# Input
n = int(input())
sequence = list(map(int, input().split()))

# Initial complexity
initial_complexity = calculate_complexity(sequence)
print(initial_complexity)

# Process updates
m = int(input())
for _ in range(m):
    index, value = map(int, input().split())
    index -= 1  # Adjust index to 0-based
    if sequence[index] != value:
        update_sequence(sequence, index, value)
        current_complexity = calculate_complexity(sequence)
        print(current_complexity)
    else:
        print(initial_complexity)
  