
def palindrome(s):
    sum=0
    c=""
    s=list(s)
    d=set()
    for char in s:
        if char not in d:
            d.add(char)
        else:
            d.remove(char)
    if len(d)>1:
        return (-1)
    elif len(d)==1:
        c=next(iter(d))
    if c:
        ic=s.index(c)
        s.pop(ic)
        s.insert(len(s)//2,c)
        sum+=abs(ic-len(s)//2)
    # c: unique char
    # remvoe outer


    # step 1 get odd char to center
    # print(c)
    # print(s)
    # print(sum)

    #step 2: edges
    while len(s)>1:
        # print("before :", s)
        c1=s[0]
        c2=s[-1]
        i1=-1 # left to end 
        i2=-1 # right to begin 
        if c1==c2:
            s.pop(0)
            s.pop(-1)
        else: # move right or left ?
            # index of last left:
            for i in range(len(s)-1,-1,-1): # from last to first index
                if s[i]==c1:
                    i1=i # distance from last to
                    # print(c1)
                    # print("d1: ",i1)
                    # # exit() 
                    break
            for i in range(0,len(s)): 
                if s[i]==c2:
                    i2=i
                    break
            if len(s)-1-i1<i2: # distance right smaller than distance left
                # print("remove: ",s[0])
                sum+=len(s)-1-i1
                s.pop(i1)
                s.pop(0)
            else: # distance left smaller or equale right
                # print("remove: ",s[-1])
                sum+=i
                s.pop(i2)
                s.pop(-1)
        # print("after: ",s)
        # print(sum)
    return sum

s=input()
print(palindrome(s))  