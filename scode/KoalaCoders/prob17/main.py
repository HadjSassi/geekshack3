def honction(ch):
    l=[]
    ch2 = ch
    while ch2.find('tt')!=-1 :
        p=ch2.find('tt')
        #print(ch2)
        ch1=ch[:p]+'v'+ch[p+2::]
        l.append(ch1)
        ch2=ch2[:p]+'*'+ch2[p+1::]
    ch2=ch
    while ch2.find('vv')!=-1 :
        p=ch2.find('vv')
        #print(ch2)
        ch1=ch[:p]+'t'+ch[p+2::]
        l.append(ch1)
        ch2=ch2[:p]+'*'+ch2[p+1::]
    return l
def kamalt(S):

    for i in S:

        if (i.find("tt") != -1 or i.find("vv") != -1):

            return False
    return True
k=[input()]
s=honction(k[0])
aux=[]

while not(kamalt(s)):

    aux =[]
    for ch in s :
        aux+=honction(ch)
    k+=s
    s=aux.copy()
k+= s
print(len(set(k)))