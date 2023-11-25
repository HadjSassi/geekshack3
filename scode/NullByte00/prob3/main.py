s = input()

res=0
if s.find("chouka") == -1 or s.find("chak") == -1:
    print(res)
else:
    i=0
    while i <len(s):
        if s[i:i+4] == "chak":
            if s[i+3:].find("chouka"):
                res+=  s[i+4:].count("chouka")
            else:
                break
            i+=4
        else:
            i+=1



print(res) 