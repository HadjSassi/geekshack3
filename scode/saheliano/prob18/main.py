def read_inputs():
    n= int(input())
    s = input().split()
    return s
def replace_in_list(a, b, s, start):
    ct = 0
    for i in range(start, len(s)):
        if s[i] == a :
            ct +=1
            s[i] = b
    return  ct
def two_equal(s:list):
    for ind, element in enumerate(s):
        try:
            same_ind = s.index(element, ind+1)

            if same_ind > ind+1:
                return ind, same_ind
        except:
            pass
    return False
def update(s, count):
    eq = two_equal(s)
    if eq==False:
        return count
    else:
        ind, same_ind = two_equal(s)
        for i in range(ind+1, same_ind):
            caract = s[i]
            s[i] = s[ind]
            count += 1
            count += replace_in_list(caract, s[ind], s, same_ind+1)
        return update(s, count)

if __name__ == '__main__':
    s = read_inputs()
    print(update(s, 0))
 