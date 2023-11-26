kc=input()
rc=input()
wc=input()
if(rc[1]==wc[1]==kc[1] and (wc[0]<kc[0]<rc[0] or rc[0]<kc[0]<wc[0]))  or (rc[0]==wc[0]==kc[0] and (wc[1]<kc[1]<rc[1] or rc[1]<kc[1]<wc[1])):
    print("NO")
else:
    print("YES")   