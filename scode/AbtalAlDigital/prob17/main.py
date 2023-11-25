def count(s):
    count_tt = s.count('tt')
    count_vv = s.count('vv')
    result = int((pow(2, count_tt-1) + pow(2, count_vv-1)))
    
    return result

s = input()
result = count(s)
print(result)