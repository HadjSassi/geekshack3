def count_delicious_substrings(s):
    count = 0
    s_len = len(s)

    for i in range(s_len):
        for j in range(i + 1, s_len + 1):
            substring = s[i:j]
            if substring.startswith("chak") and substring.endswith("chouka"):
                count += 1

    return count

s = input().strip()

result = count_delicious_substrings(s)
print(result)