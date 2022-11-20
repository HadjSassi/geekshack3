d={1:'take_position',10:'run',100:"need_backup",1000:'declare_your_position'}
ch=input()
L=ch.split(' ')
try:
    for i in range(len(L)):
          L[i]=int(L[i])
    ch1=''
    d1={1:1,2:10,4:100,8:1000}
    for c in L:
            if c in d1.keys():
                ch1+=d[d1[c]]+' '
            else :
                
                j=c-1
                while(c>0):
                    if j in d1:
                        ch1+=d[d1[j]]+' '
                        c=c-j
                        j=c
                    else :
                        j=j-1
                    
                        
                        
    print(ch1[0:len(ch1)-1])
except :
    print('NOT_CLEAR')
 