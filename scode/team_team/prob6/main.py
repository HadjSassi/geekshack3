def divisors(n):
    result = []
    for i in range(1, n//2 + 1):
        if n % i == 0:
            result.append(i)
    result.append(n)
    return result
n=int(input())
c,ch=(input().split())
l=divisors(n)
if c=='E':
    for i in l[::-1]:
     ch=ch[i-1::-1]+ch[i:]
    print (ch)
if c=='D':
    for i in l:
     ch=ch[i-1::-1]+ch[i:]
    print (ch)
    
 