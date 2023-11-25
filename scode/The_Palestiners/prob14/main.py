S=input()
def PalindromeSwapper(S):
    length = len(S)
    for idx, i in enumerate(S):
        if idx == length-1: return -1  # if idx==length-1, then t[idx+1] will give IndexError
        t = list(S)  # make list, so swapping is possible
        t[idx], t[idx+1]  = t[idx+1], t[idx]  # swap characters
        t = ''.join(c for c in t)  # rebuild string from list
        if t == t[::-1]: return t  # palindrome condition
        
print(PalindromeSwapper(S))