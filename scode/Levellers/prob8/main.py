s= input()
if(s.isalpha()):
    print("NO")
else:
    l=s.split(" ")
    if(len(l)<4):
        print("NO")
    else:
        print(int(l[0])*int(l[2]))
    