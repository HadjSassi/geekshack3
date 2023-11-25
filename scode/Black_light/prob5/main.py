
r=input()
k=input()
w=input()
if r[1]==k[1] and r[1]==w[1] :
    if abs(int(r[2])-int(k[2]))>abs(int(r[2])-int(w[2])):
        print("YES")
    else:
        print("NO")
elif r[2]==k[2] and r[2]==w[2] :
    if abs(ord(r[1])-ord(k[1]))>abs(ord(r[1])-ord(w[1])):
            print("YES")
    else:
        print("NO")
else :
    print("YES")
        
        
    
        