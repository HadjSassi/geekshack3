def tv():
    s=input()
    s1= s[::-1]
    ctr=1
    test1=False
    for i in range(1,len(s1)):
        if test1==True: pass
        else:
         ch1=s1[i]+s1[i-1]
        if ch1=='tt':
          test1=True
          ctr+=1
          s1.replace(s[i],'v')
          s1.replace(s1[i-1],'')
        if ch1=='vv':
          test1=True
          ctr+=1
          s1[i]='t'
          s1[i-1]=''  
    return ctr    

print(tv())            