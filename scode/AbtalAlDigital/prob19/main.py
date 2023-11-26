hand=map(input().split())
def fourmat(L,n):
    Foumation=set()
    numbers=[]
    b=False
    for card in L:
        card[0].add(Fourmation)
        if card[1]=="j":
            numbers.append(11)
        if card[1]=="Q"
            numbers.append(12)
        if card[1]=="k":
            numbers.append(13)
        else:
            numbers.append(int(card[1]))
    if len(fourmation)==len(l):
        b=True
    numbers.sort()
    a=True
    for i in range(1:n+1):
        if i!=numbers[i]:
            a=False
    if((a==True and b ==False) or (b==True and len(number)==1)):
        return True
    else :
        return False