ch=input()
l=[ch]
i=1
def cpt(ch,c):
    s=0
    for i in range(len(ch) - 1):
        if ch[i:].find(c)==0:
            s+=1
    return s


while 'tt' in ch or 'vv' in ch:
    ch = ch.replace('tt', 'v', 1)
    if ch not in l:
        l.append(ch)
    ch = ch.replace('vv', 't', 1)
    if ch not in l:
        l.append(ch)

for j in l :
    i+= cpt(j,'tt')+cpt(j,'vv')


print(i)
