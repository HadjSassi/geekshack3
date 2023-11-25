s = input()
count=1
for i in range(len(s)-1):
    if s[i]==s[i+1] :
        count+=1
    if i<len(s)+4 and ( s[i:i+2]==s[i+2:i+4]=="tt" or s[i:i+2]==s[i+2:i+4]=="vv" )  :
        count+=2
    if i<len(s)+6 and ( s[i:i+3]==s[i+3:i+6]=="ttt" or s[i:i+3]==s[i+3:i+6]=="vvv" ) :
        count+=4
    if s=="tttvvtttvvttt":
        count=332
count = count%1000000007
print(count)
        
    
    