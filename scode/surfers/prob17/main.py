

def check( s) :
    list=[]
    if ('tt' not in s) and ('vv' not in s):
        return list;
    else:
        for i in range(len(s)-1):
            if (s[i] == 't') and (s[i+1] == 't'):
                str1=s[0:i] + 'v' + s[i+2:len(s)]
                if str1 not in list:
                    list.append(str1)
                    list=list+(check(str1))
              
            if (s[i] == 'v') and (s[i+1] == 'v'):
                str1=s[0:i] + 't' + s[i+2:len(s)]
                if str1 not in list:
                    list.append(str1)
                    list=list+(check(str1))
                
                
    return list



s = input()
l=check(s)
l.append(s)
auxiliaryList = []
for i in range(0,len(l)):
    if l[i] not in auxiliaryList:
        auxiliaryList.append(l[i])
print(len(auxiliaryList))


