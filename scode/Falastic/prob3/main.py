s=input()
ans=0
while (s.count("chouka")!=0):
    index=s.rfind("chouka")
    s=s[0:index]
    ans+=s.count("chak");
print(ans)
