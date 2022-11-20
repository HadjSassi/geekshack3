open=['{','(','[',"'",'"']
close=['}',')',']',"'",'"']
s=input()
queue=[]
r=[]
cnt=""
passed=[]
for i in range(len(s)):
    if s[i] in open and i not in passed:
        cnt=s[i]
        j=i
        queue=[]
        queue.append(s[j])
        while len(queue)!=0 and j<len(s)-1:
            j+=1
            cnt+=s[j]
            if s[j]==close[open.index(queue[len(queue)-1])]:
                passed.append(j)
                queue.pop()
            elif s[j]==s[i]:
                queue.append(s[j])
            if len(queue)==0:
                r.append(cnt)
#print(r)
if len(r)==0:
    print("SYNTAX_ERROR")
for i in range(len(r)):
    if i!=len(r)-1:
        print(r[i],end=(' '))
    else:
        print(r[i])