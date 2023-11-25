s=input()
nb=1
for i in range(len(s)-2):
      if s[i]+s[i+1]=="tt":
        s=s[i-1]+"v"+s[i+2]
        nb+=1
      if s[i]+s[i+1]=="vv":
        s=s[i-1]+"t"+s[i+2]
        nb+=1

    
    
print(nb%1000000007)
      