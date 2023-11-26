s=input()
def palindrome(s: str, n: int) -> int:
    cnt = dict()
    R = []
    for i in range(n):
        a = s[i]
        if a in cnt:
            cnt[a] += 1
        else:
            cnt[a] = 1
    i = 'a'
    while i <= 'z':
        if i in cnt and cnt[i] % 2 != 0:
            R += i
        i = chr(ord(i) + 1)
 
    l = len(R)
    j = 0
    for i in range(l - 1, (l // 2) - 1, -1):
        if R[i] in cnt:
            cnt[R[i]] -= 1
        else:
            cnt[R[i]] = -1
 
        R[i] = R[j]
 
        if R[j] in cnt:
            cnt[R[j]] += 1
        else:
            cnt[R[j]] = 1
        j += 1
    first, middle, second = "", "", ""
 
    i = 'a'
    while i <= 'z':
        if i in cnt:
            if cnt[i] % 2 == 0:
                j = 0
 
                # fill the first half.
                while j < cnt[i] // 2:
                    first += i
                    j += 1
            else:
                j = 0
                while j < (cnt[i] - 1) // 2:
                    first += i
                    j += 1
                middle += i
        i = chr(ord(i) + 1)
    second = first
    second = ''.join(reversed(second))
    resultant = first + middle + second
    print(resultant)
 
# Driver Code
if __name__ == "__main__":
 


    palindrome(s, len(s))