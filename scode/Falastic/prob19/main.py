m={}
arr=["J","Q","K","A"]
t=input().split();
for key in t:
    if key[1:] in arr:
        value=11+arr.index(key[1:])
    else :
        value=int(key[1:])
    if key[0] in m :
            m[key[0]].append(value)
    else :
        m[key[0]]=[value]
sum=0;
rest=[]
for key in m :
    newsum,nb=0,0
    arr=m[key]
    for i in range(1,len(arr)): 
        if (arr[i]-arr[i-1]==1):
            nb+=1
            if (arr[i-1]>10):
                newsum+=10
            else:
                newsum+=arr[i-1]
        if (nb>=2 and (i==len(arr)-1 or arr[i]-arr[i-1]!=1)):
            m[key]=m[key][:i-nb]+m[key][i:]
            if (arr[i]-arr[i-1]==1):
                m[key].remove(arr[i])
                if (arr[i]>10):
                    newsum+=10
                else:
                    newsum+=arr[i]
            sum+=newsum
            newsum,nb=0,0
    rest+=m[key]
for value in set(rest) :
    nb=0
    for key in m :
        if value in m[key]:
            nb+=1
    if nb>=3:
        sum+=nb*value;
if sum>=72:
    print("YES",sum)
else:
    print("NO")
    
         