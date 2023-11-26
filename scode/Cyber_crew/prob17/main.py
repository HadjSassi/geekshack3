ch=input()

if 'tt'not in ch and 'vv'not in ch:
    print('1')
else:
    n=1
    while(len(ch)>1):
        if 'tt'in ch:
            n+=ch.count('tt')
            x=ch.index('tt')
            ch=ch.replace(ch[x:x+2],'v')
        elif 'vv' in ch:
            n+=ch.count('vv')
            x=ch.index('vv')
            ch=ch.replace(ch[x:x+2],'t')
    print(n)
        
    
    