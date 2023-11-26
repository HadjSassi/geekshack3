def harmonized_sequence(N, A):
    # Create a mapping of each element to its current position
    position_map = {A[i]: i for i in range(2*N)}

    # Function to swap two elements in the sequence
    def swap(i, j):
        A[i], A[j] = A[j], A[i]
        position_map[A[i]] = i
        position_map[A[j]] = j

    # Initialize the number of swaps
    swaps = 0

    # Iterate through each element from 1 to N
    for i in range(1, N+1):
        # Find the current position of the first occurrence of i
        current_pos = position_map[i]

        # Calculate the target position for the first occurrence of i
        target_pos = 2 * (i - 1)

        # Check if a swap is needed
        while current_pos != target_pos:
            # Swap the first occurrence of i with the second occurrence
            swap(current_pos, target_pos)

            # Increment the number of swaps
            swaps += 1

            # Update the current position after the swap
            current_pos = target_pos

            # Calculate the new target position for the first occurrence of i
            target_pos = 2 * (i - 1)

    print(" ".join(map(str, A)))

# Example usage:
N = int(input())
A = list(map(int, input().split()))

harmonized_sequence(N, A)
