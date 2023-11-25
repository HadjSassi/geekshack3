BK=input()
BR=input()
WK=input()
if((BR[1:][0] == WK[1:][0] and BK[1:][0] == WK[1:][0] ) or (BR[1:][1] == WK[1:][1] and BK[1:][1] == WK[1:][1])):
    print("NO")
else:
    print("YES") 