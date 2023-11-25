r=input()
k=input()
w=input()
if(r[1]==k[1]and k[1]==w[1]):
   if ((r[2]<k[2]and k[2]<w[2])or(w[2]<k[2]and k[2]<r[2])):
     print('NO')
elif(r[2]==k[2]and k[2]==w[2]):
   if ((r[1]<k[1]and k[1]<w[1])or(w[1]<k[1]and k[1]<r[1])):
       print('NO')
else :
  print ('YES')