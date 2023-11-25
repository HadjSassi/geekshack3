s=input()
ch="tt"
ch1="vv"
ch3='tv'
x=""
p=1

for i in range(len(s)):
    if s[i:i+2]==ch :
        x=s.replace(s[i:i+2],'v')
        p+=1
        for j in range(len(x)):
            if x[i:i+2]==ch :
               x=s.replace(s[i:i+2],'v')
               p+=1
            elif x[i:i+2]==ch1:
               x=s.replace(s[i:i+2],'t')
               p+=1
    elif s[i:i+2]==ch1:
        x=s.replace(s[i:i+2],'t')
        p+=1
        for j in range(len(x)):
            if x[i:i+2]==ch :
               x=s.replace(s[i:i+2],'v')
               p+=1
            elif x[i:i+2]==ch1:
               x=s.replace(s[i:i+2],'t')
               p+=1
               
print(p)