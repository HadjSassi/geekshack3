try:
 n=int(input())
 main=[]
 for i in range (n):
    ch =input ()
    l=ch.split(' ',2)
    if l[1]=='Main':
        try:
         if l[2]!="A B D" :
            main.append (l[2])
        except: continue
    else :
        if (l[2]=="A B C D"):
          print("A B C D : M")
        else :
             if l[2] not in main :
                print(l[2],": U") 
 for i in main:
     print(i)
except: 
    print("NO")