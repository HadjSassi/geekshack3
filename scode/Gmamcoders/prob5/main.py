rc=input()
kc=input()
wc=input()
if ((rc[2]==kc[2]==wc[2] )and ((rc[1]<kc[1]<wc[1])or(wc[1]<kc[1]<rc[1])))or((rc[1]==kc[1]==wc[1] )and ((rc[2]<kc[2]<wc[2])or(wc[2]<kc[2]<rc[2]))) :
    print("NO")
else:
    print("YES") 


