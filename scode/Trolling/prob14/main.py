while 1:
    s=input()
    L=s.split(' ')
    if '' in L:
        L.remove('')
    w=int(L[0])
    l=int(L[1])
    T_size=int(input())
    a=input()
    if a.isnumeric():
        T_number=int(a)
    else:
        print("INPUT_ERROR")
        break
    r=0
    k=0
    while(r>=0):
        r=w-k*T_size-k+1
        k+=1
    max_w=k-2
    r=0
    k=0
    while(r>=0):
        r=l-k*T_size-k+1
        k+=1
    max_l=k-2
    margin_w=w-max_w*T_size-max_w+1
    margin_l=l-max_l*T_size-max_l+1
    cnt=0
    if T_number==1 and max_w>1 and max_l>1:
        print("4")
    elif T_number==0:
        print("0")
    else:
        if T_number<=max_w and (margin_w>=margin_l or not T_number<=max_l):
            cnt+=T_number*2 - 2 + min(2,w-T_number*T_size-T_number+1)+2*T_number
        elif T_number<=max_l:
            cnt+=T_number*2 - 2 + min(2,l-T_number*T_size-T_number+1)+2*T_number
        elif margin_l<=margin_w:
            if T_number%max_w==0:
                cnt+=(max_l*2 - 2 + margin_l)*(T_number//max_l)+((T_number//max_l)*2 - 2 + min(2,w-(T_number//max_l)*T_size-(T_number//max_l)+1))*max_l
            else:
                cnt+=(max_l*2 - 2 + margin_l)*(T_number//max_l)+((T_number//max_l)*2 - 2 + min(2,w-(T_number//max_l)*T_size-(T_number//max_l)+1))*max_l +3*(T_number%max_l)
                if margin_w==2:
                    cnt+=(T_number%max_l)
        print(cnt)
    break