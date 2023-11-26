
ch=input()

if 'tt'not in ch and 'vv'not in ch:
    print('1')
else:
    n=2
    while(len(ch)>1):
        if 'tt'in ch:
            n+=ch.count('t')-1
            
            x=ch.index('tt')
            ch=ch.replace(ch[x:x+2],'v')
        elif 'vv' in ch:
            n+=ch.count('v')-1
            ch=ch.replace(ch[x:x+2],'t')
    print(n)
    
            