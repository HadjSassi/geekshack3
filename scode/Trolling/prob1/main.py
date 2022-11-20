n=int(input())
for i in range(n):
    s=input()
    s=s.replace(" ","")
    cnt=0
    for j in range(len(s)//2):
        cnt+=abs(ord(s[j])-ord(s[len(s)-1-j]))
    print(cnt)
             