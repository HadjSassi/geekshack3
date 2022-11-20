
def palindrome(ch):
    oper = 0
    for i in range(len(ch)//2):
        oper += abs(ord(ch[i])-ord(ch[len(ch)-i-1]))
    return oper
    
n = int(input())

#words = list(input().strip().split())


for i in range(n):
    word = input().strip()
    print(palindrome(word))


