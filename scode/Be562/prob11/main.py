try :
    ch=input()
    l=ch.split()
    for i in range (len(l)):
        l[i]=int(l[i])
    n=sum(l)
    x=bin(n)
    x=int(x[2:])
    l=[]

    if(x-1000)>=0:
        x=x-1000
        l.extend(['declare_your_position'])
    if(x-100)>=0:
        x=x-100
        l.extend(['need_backup'])
    if(x-10)>=0:
        x=x-10
        l.extend(['run'])
    if(x-1)>=0:
        x=x-1
        l.extend(['take_position'])
        


    ch2=' '.join(l)
    print(ch2)
except :
    print('NOT_CLEAR')

    
  