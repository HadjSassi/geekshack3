import math

# Function to calculate power of clans
def power_of_clans(clans, soldiers):
    mod = 10**9 + 7
    power = 0

    for clan in clans:
        strength = 1
        for i in clan:
            strength = (strength * soldiers[i-1]) % mod
        power = (power + strength) % mod
    return power

# Read input
n = int(input())
soldiers = list(map(int, input().split()))

# Sort soldiers based on strength
soldiers = sorted(range(n), key=lambda i: soldiers[i])

# Calculate power of clans
power = power_of_clans(soldiers, soldiers)

# Print output
print(power)