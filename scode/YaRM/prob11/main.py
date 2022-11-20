def decode():
    switcher={
        1:'take_position',
        2:'run',
        4:'need_backup',
        8:'declare_your_position'}
    ch=input()
    ch=ch.split()
    try:
        a=int(ch[0])
        if len(ch)==2:
            b=int(ch[1])
            print(switcher.get(a)+' '+switcher.get(b))
            return
        else:
            s=''
            if a>=8:
                s+=switcher.get(8)+' '
                a-=8
            if a>=4:
                s+=switcher.get(4)+' '
                a-=4
            if a>=2:
                s+=switcher.get(2)+' '
                a-=2
            if a>=1:
                s+=switcher.get(1)+' '
                a-=1
            print(s[0:len(s)-1:])
            
            
    except:
        print('NOT_CLEAR')
decode()
        