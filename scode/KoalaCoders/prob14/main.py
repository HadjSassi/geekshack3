def is_palindrome(s):
    return s == s[::-1]

def perm(ch):
    if is_palindrome(ch):
        return 0
    cc = {}
    oc = 0
    for c in ch:
        if c.isalpha():
            cc[c] = cc.get(c, 0) + 1

    for count in cc.values():
        if count % 2 != 0:
            oc += 1

    if oc > 1:
        return -1

    return (len(ch) - oc) // 2
ch = input()
r = perm(ch)
print(r)  




