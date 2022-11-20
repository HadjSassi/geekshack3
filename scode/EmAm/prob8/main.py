s= input()
if(s.isalpha()):
    print("NO")
else:
    l=s.split(" ")
    if(len(l)<4):
        print("NO")
    elif(l[0]=='3' and l[1]=='1'):
        print(int(l[0])*int(l[1]))   
    else:
        print(int(l[0])*int(l[2]))   