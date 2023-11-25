s = input("")
c = s.lower()
n=0;
for i in range(len(c)-1) :
    if ((c[i] == 'c') and (c[i+1]=='h')):
        for j in range(i+1,len(c)+1):
            if (c[i:j].startswith('chak') and c[i:j].endswith('chouka')):
                n=n+1
print(n)  