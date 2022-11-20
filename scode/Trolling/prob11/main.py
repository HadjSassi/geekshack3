while 1:
    s=input()
    try:n=int(s)
    except:
        s2=s.replace(" ","")
        if s2.isnumeric():
            L=s.split(" ")
            n=sum([int(i) for i in L])
        else:
            print("NOT_CLEAR")
            break
    r=0
    rs=""
    for i in range(3,-1,-1):
        if n-2**i>=0:
            r+=10**i
            n-=2**i
            if len(rs)!=0:
                rs+=" "
            if i==3:
                rs+="declare_your_position"
            elif i==2:
                rs+="need_backup"
            elif i==1:
                rs+="run"
            elif i==0:
                rs+="take_position"
    print(rs)
    break
