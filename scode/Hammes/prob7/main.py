ch=input()
l=ch.split(" ")
n=int(l[0])
z=int(l[1])
tab=[]
tab1=[]
for i in range(n):
    ch=input()
    j=0
    k=0
    for i in range(len(ch[0])):
        tab.insert(j,ch[0])
    for i in range(len(ch[0])):
        tab1.insert(j,ch[2])

s=0
def findsum(x):
    numbers = []
    numOfOnes= x - 2
    numbers.append([1]*x) # all ones
    numbers.append([1] * numOfOnes + [2]) #all ones and a two
    if x % 2 == 0:
        numOfTwos = int((x - 2)/2)
        numbers.append([2]*(int(x/2))) # all twos
        if x >= 6:
            numbers.append([2] * numOfTwos+ [1,1]) #all twos and 2 ones

    else:
        numOfTwos = int((x - 1)/2)
        numbers.append([2] * numOfTwos+ [1])

    return numbers 
result=findsum(z);
for i in result:
    if len(i)>n:
        result.pop(result.index(i))
        
s=0;
tab_s = []
tab_r=[]
x=0;
first = [eval(i) for i in tab]
second = [eval(i) for i in tab1]
res=first.copy()
res1=second.copy()
for i in (result):
    tab_r.append(tab_s)
    for j in ((i)):
        if j == 1 :
            if(len(res)>0):
                m=min(res)
                indice=res.index(min(res))
                res.pop(indice)
            
                res1.pop(indice) 
               
                s=s+m;
               
                tab_s.append(s)
            if (len(res)==0) and (j!=len(res)):
                tab_s.clear()
        else:
            
            if(len(res1)>0):
                indice=res1.index(min(res1))
                m=min(res1)
                res.pop(indice)
                res1.pop(indice)
                s=m
                tab_s.append(s)
        
    x=x+1
    s=0
    res,res1=first,second

tb=[]
second=[]
first=[]
for i in tab_r:
    tb.append(sum(i))
tb.sort()
print(tb[0])
  