ch = input()
j=0
while (j < len(ch)//2):
    if ch[j+1::].find(ch[j]) != -1:
        ch = ch[:j]+ch[j+1::]+ch[j]
    else:

        ch= ch.replace(ch[-j-1],ch[j])
    j+=1
print(ch)