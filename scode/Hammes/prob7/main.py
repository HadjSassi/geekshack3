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
s=0;
tab_s = []
x=0;
res = [eval(i) for i in tab]
res1 = [eval(i) for i in tab1]
print(min(res))