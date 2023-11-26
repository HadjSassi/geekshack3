def occ(word,c):
    counter = {}
    for letter in word:
        if letter not in counter:
            counter[letter] = 0
        counter[letter] += 1
    return counter[c]
n=int(input())
c=input()
cpx=0
i=1
while(i<len(c)):
    while(c[i]==c[i-1]):
        i+=1
    if(occ(c,c[i-1])!=i):
       cpx+=occ(c,c[i])
       c=c.replace(c[i],c[i-1])
print(cpx)
