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
res,res1=first,second
for i in (result):
    print("-------+++-")
    print(tab_s)
    tab_r.append(tab_s)
    print(tab_r)
    for j in ((i)):
        print(j)
        if j == 1 :
            if(len(res)>0):
                m=min(res)
                indice=res.index(min(res))
                m=min(res)
                print("le min est ",m)
                res.pop(indice)
            
                res1.pop(indice) 
               
                s=s+m;
               
                tab_s.append(s)
                print("----",tab_s)
            else:
                print("hhh")
                tab_s.clear()
        else:
            if(len(res1)>0):
                indice=res1.index(min(res1))
                m=min(res1)
                res.remove(indice)
                res1.remove(indice)
                s=s+m
                tab_s[x]=s
        
    x=x+1
    res,res1=first,second

print(tab_s)