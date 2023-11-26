r=input()
k=input()
c=input() 
if (r[2]!=c[2] or r[2]!=k[2] )and (r[1]!=c[1] or r[1]!=k[1]):
    if ord(r[1])!=ord(c[1])-1 and ord(r[1])!=ord(c[1])+1:
        
           print('YES')
    elif ord(k[1])==ord(c[1])-1 or ord(k[1])==ord(c[1])+1 or ord(k[1])==ord(c[1]):
        if (int(r[2]))-int(c[2])==1 or (int(r[2]))-int(c[2])==-1 and ord(r[1])!=ord(c[1]):
           print('YES')
    elif int(r[2])-int(c[2])==1 or (int(r[2]))-int(c[2])==-1 or int(k[2])==int(c[2:]):
        if ord(r[1])==ord(c[1])-1 or ord(r[1])==ord(c[1])+1: 
           print('YES')

else:
    print('NO')
        