deb=["(","\'","\"","{","["]
fin=[")","\'","\"","}","]"]
def finddeb(ch):
    try:
        for x in ch:
            if x in deb:
                return ch.index(x)
        return -1
    except:
        return -2
def findfin(d,ch):
    try:
        f=fin[deb.index(d)]
        for x in range (len(ch)):
            if ch[x]==f:
                return x
        return -1
    except:
        return -2
          
        
def cal():
    s=''
    ch=input()
    n=len(ch)
    d=0
    l=[]
    while d <= n:
        d=finddeb(ch)
        if d==-1 or d==-2:
            break
        f=findfin(ch[d],ch[d+1::])
        if f==-1 or f==-2:
            if len(ch)==n:
                print('SYNTAX_ERROR')
                return 
            else:
                d+=1
        else:
            l.append(ch[d:f+2+d:]) #mot
            d=f+2+d
            ch=ch[d::]
            
    for x in l:
        s+=x+' '
        m=x[1:len(x)-1:]
        d=finddeb(m)
        while d!=-1 and d!=-2:
            f=findfin(m[d],m[d+1::])
            if f==-1 or f==-2:
                m=m[d+1::]
                d=finddeb(m)
            else :
                s+=m[d:f+2+d:]+" "
                m=m[f+2+d::]
                d=finddeb(m)
    print(s[:len(s)-1:])
    
cal()
