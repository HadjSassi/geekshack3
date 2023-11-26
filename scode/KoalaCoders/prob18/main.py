def rep_list(l,el,value):
    for i in range(len(l)):
        if l[i] == el:
            l[i] = value
    return l
n = int(input())
ch = input().split()

index = 0
t=0
p = 0
while t != len(ch)-1:
    c = ch[index]
    try:
        t = (['*']*len(ch[:index+1])+ch[index+1::]).index(c)
    except:
        t = -1
    #print('t' ,t)
    #print('c',c)
    if t == -1:
        if (index < len(ch) - 1):
            index +=1
        t = index
    else:
        compteur = 0
        l=[]
        for j in range(index+1,t):
            #print(ch[j])
            if not(ch[j] in l):
                l.append(ch[j])
                compteur += ch.count(ch[j])
        #print('com',compteur)
        #print(ch.count(c))
        #print('c',c)
        #print('ind', index)
        if compteur < ch.count(c):
            for i in range(index+1,t):
                if ch[i] != c:
                    #print("hey")
                    p += ch.count(ch[i])
                    #print(p, ch[i])

                    ch= rep_list(ch,ch[i],c)


            index = t
        else:
            lista =[]
            for e in l:
                lista.append(ch.count(e))
            i = lista.index(max(lista))
            p+=ch.count(c)
            ch = rep_list(ch,c,l[i])
            t = 0
#print(ch)
print(p)
