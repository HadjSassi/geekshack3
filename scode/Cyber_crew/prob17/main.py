def occ(ch,ch1):
    n=0
    for i in range (len(ch)-1):
        if ch[i:i+2]==ch1:
            n+=1
    return n
ch=input()

if 'tt'not in ch and 'vv'not in ch:
    print('1')
else:
    n=2
    while(len(ch)>1):
        if 'tt'in ch:
            n+=occ(ch,'tt')
            x=ch.index('tt')
            ch=ch.replace(ch[x:x+2],'v')
        elif 'vv' in ch:
            n+=occ(ch,'vv')
            x=ch.index('vv')
            ch=ch.replace(ch[x:x+2],'t')
    print(n)
        
    
        