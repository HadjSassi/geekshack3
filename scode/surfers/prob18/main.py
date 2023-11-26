from collections import Counter

def beautify(seq):
    # only mod4 is interesting, count 1s, 2s, and 3s
    c = Counter(x % 4 for x in seq)
    c1, c2, c3 = c.get(1, 0), c.get(2, 0), c.get(3, 0)
    steps22, twos = divmod(c2, 2)  # you have either 0 or 1 2s left
    steps13, ones_or_threes = min(c1, c3), abs(c1 - c3)
    if not twos and not ones_or_threes % 4:
        # 3 steps for every quadruple of 1s or 3s
        return steps22 + steps13 + 3 * ones_or_threes // 4  
    if twos and ones_or_threes % 2 == 2:
        # 2 extra steps to join the remaining 2 1s or 3s with the remaining 2
        return steps22 + steps13 + 3 * ones_or_threes // 4 + 2
    return -1
def two_sum(numbers, k):
    n = len(numbers)

    for i in range(0, n):
        for j in range(i+1, n):
            if (numbers[i] + numbers[j]) % k == 0:
                return numbers[i], numbers[j]
    return None
def rec_helper(numbers, k, count):
    if all(x % k == 0 for x in numbers):
        return count

    # probably safer to check if two_sum() is not None here
    first, second = two_sum(numbers, k)

    numbers.remove(first)
    numbers.remove(second)
    numbers.append(first + second)

    return rec_helper(numbers, k, count + 1)
def beautiful_array(numbers, k):
    if sum(numbers) % k != 0:
        return -1

    return rec_helper(numbers, k, 0)
print(beautiful_array([6, 6, 3, 3, 4, 4], 4))