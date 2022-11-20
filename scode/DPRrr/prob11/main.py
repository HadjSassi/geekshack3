try:
    N=list(map(int, (input().strip().split())))

    l=[]
    for i in (N):
        ch=''
        while(i // 2)!=0:
            ch=str(i % 2)+ch
            i=i // 2
        ch=str(i % 2)+ch
        l.append(int(ch))

    for i in l:
        k=i
        a=[]
        if i in [1,10,100,1000]:
            continue
        if i>=1000:
            i-=1000
            a.append(1000)
        if i>=100:
            i-=100
            a.append(100)
        if i>=10:
            i-=10
            a.append(10)
        if i<10:
            a.append(i)
        b=l.index(k)
        l[b]=a
    for i in l:
        if type(i)==int:
            l[l.index(i)]=[i]

    chaine=''
    for i in l:
        for j in i:
            if j==1:
                chaine+='take_position '
            elif j==10:
                chaine+='run '
            elif j==100:
                chaine+='need_backup '
            elif j==1000:
                chaine+='declare_your_position '
    chaine1=chaine.rstrip(chaine[-1])
    print(chaine1)
except ValueError:
    print('NOT_CLEAR')