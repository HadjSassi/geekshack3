T=[]
n=int(input())
for i in range (n):
       ch=input()
       l=ch.split(' ')
       T.append(l)

m=len(l)
nb=0
i=0
j=0
while(i<n):
    while(j<m):
        if (T[i][j]==1)and(i>=1)and(j>=1):
             if (T[i-1][j]==2):
                 if (T[i-1][j-1]==3):
                     if (T[i][j-1]==4):
                         nb+=1
                         j+=1

             elif (T[i][j-1]==2):
                  if (T[i-1][j-1]==3):
                      if (T[i-1][j]==4):
                          nb+=1
                          j+=1
        elif ( T[i][j]==1) :
               if (T[i+1][j]==2):
                   if( T[i+1][j+1]==3):
                        if (T[i+1][j]==4):
                            nb+=1
                            j+=1

               elif (T[i][j+1]==2):
                   if T[i+1][j+1]==3:
                       if T[i+1][j]==4:
                           nb+=1
                           j+=1
    print(i)
    i+=1
     

print(nb)

     
  