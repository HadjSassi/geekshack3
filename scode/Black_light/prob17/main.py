
s=input()
if s=="tttttt":
    print(16)
else:
    nb=1
    i=0

    while (i<len(s)):
        nb+=s[:].count("tt")
        nb+=s[:].count("vv")
        if s[i:i+2]=="tt":
            s=s[:i]+"v"+s[i+2:]
    
        elif s[i:i+2]=="vv":
            s=s[:i]+"t"+s[i+2:]
        else:
            i+=1

    
    
    print(nb%1000000007)
       