r=input()
k=input()
c=input() 
if ord(r[1])==ord(c[1])-1 or ord(r[1])==ord(c[1])+1:
    if (int(r[2]))-int(c[2])==1 or (int(r[2]))-int(c[2])==-1:
        print('YES')
else:
    print('NO')
        
    