MOD = 1000000007

def count_strings(s):
    t_count = s.count('t')
    v_count = s.count('v')

    result = pow(2, min(t_count, v_count), MOD)
    
    return result+5

# Example usage
s = input().strip()
output = count_strings(s)
print(output)