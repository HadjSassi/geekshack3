ch=str(input())
#lch=list(ch)
clos = {'{': '}', '(': ')', '[': ']'}
l=['{','(',"'",'[',"`",'"',')',']','}']
j=0
for i in ch:
    if i in l:
        if i in ['(','{','[']:
            if ch.count(i)!=ch.count(clos[i]):
                print("SYNTAX_ERROR")
                j=1
                break
            
        if  ch.count(i)%2!=0:
            continue
        else:
            j+=1
if j==0:
    print("SYNTAX_ERROR") 