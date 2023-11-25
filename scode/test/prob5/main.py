n=int(input())
C,s=map(str,input().split())
if C=='D':
  for i in range(1, n+1):
    if n%i==0:s=s[:i][::-1]+s[i:]
  print(s)
else:
    for i in range(n+1,1,-1):
        if n%i==0:s=s[:i][::-1]+s[i:]
    print(s)  