n = int(input())
ch = input()
l = ch.split()
ch = l[1]
div = []

for i in range(1,n+1):
    if n % i ==0 :
        div.append(i)
if l[0] == "E":
    div = div[::-1]

for i in div :
    ch = ch[0:i][::-1]+ch[i:]
print(ch)