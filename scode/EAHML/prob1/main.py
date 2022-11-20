n=int(input())

for i in range(n):
    k=0
    ch=input()
    
    for j in range((len(ch)//2)+1):
        while (ch[j]!=ch[len(ch)-j-1]):
                if (ch[j]>ch[len(ch)-j-1]):
                    k+=ord(ch[j])-ord(ch[len(ch)-j-1])
                    ch=ch[:j]+str(ch[len(ch)-j-1])+ch[j+1:]
                elif(ch[j]<ch[len(ch)-j-1]):
                    k+=ord(ch[len(ch)-j-1])-ord(ch[j])
                    ch=ch[:len(ch)-j-1]+str(ch[j])+ch[len(ch)-j:]
                    
                    
    print(k);
