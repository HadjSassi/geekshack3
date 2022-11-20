def verif(l1, l2):
    i = 0
    while(i<len(l2)-1):
        if l2[i] in l1:
            return True
        i+=1
    return False
    
def maine():
    l=[]
    try:
        for t in range(int(input())):
            l.append(input().strip())
    except: return 'NO'

    l = [ch.split(' ') for ch in l]
    # l = [['BR', 'MAIN', '1', '2', '3'], ['BR', 'A', 'D', 'D', 'L']]

    main = l[0][1]

    d = dict()
    for li in l:
        if li[1] in d:
            d[li[1]].append(li[2:])
        else: d[li[1]] = [li[2:]]
    #if li[2:]!=[]:
     #   d[li[1]] = [li[2:]]
    #else:
     #   d[li[1]] = []
    
    d1 = d.copy()
    if d=={}:
        return 'NO'
        





    # d = {'Main': [['A', 'B', 'D'], ['5', '3', '2']],
    # 'A': [['A', 'B', 'C', 'D'], ['5', '3', '2']], 'B': [['H', 'I', 'K']]}

    for key in d.keys():
            if key!=main:
                for l1 in d[key]:
            
                    for l2 in d[main]:

                        if verif(l1, l2) and l1!=l2:
                            for c in l1:
                                if c not in l2:
                                    l2.append(c)
                    
                    
                            if l2[1]>=l2[0]:
                            #tri croissante de l2
                                l2.sort()
                        
                            else:
                            #tri decroissante
                                l2.sort(reverse=True)
                        
                            l2.append(': M')
                            break
                        elif l1 not in d[main]:
                            l1.append(': U')
                            d[main].append(l1)

    for l in d[main]:
        if l == [] : d[main].remove(l)


    lout = []
    for l in d[main]:
          if l[-1] == ': M':
                lout.append(' '.join(l))
    for l in d[main]:
            if l[-1] == ': U':
                lout.append(' '.join(l))
    for l in d[main]:
            if l[-1] != ': U' and l[-1] != ': M':
                lout.append(' '.join(l))

    return lout
x = maine()
if x == 'NO':
    print('NO')
else:
    for ch in x:
        print(ch)
