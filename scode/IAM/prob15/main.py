n=int(input())
l=[]
for i in range(n):
   ch=input()
   l.append(ch.split(" "))
if (len(l[0])==5):
    if (l[0][4]=="\r"):
            del(l[0][4])
for i in range(n):
    for j in range(len(l[0])):
        l[i][j]=int(l[i][j][0])
a=0
for i in range(n-1):
    for j in range(len(l[0])-1):
        if(
            (l[i][j]==2 and l[i][j+1]==1 and l[i+1][j]==3 and l[i+1][j+1]==4)
            or
            (l[i][j]==1 and l[i][j+1]==4 and l[i+1][j]==2 and l[i+1][j+1]==3)
            or
            (l[i][j]==4 and l[i][j+1]==3 and l[i+1][j]==1 and l[i+1][j+1]==2)
            or
            (l[i][j]==3 and l[i][j+1]==2 and l[i+1][j]==4 and l[i+1][j+1]==1)
            or
            (l[i][j]==4 and l[i][j+1]==1 and l[i+1][j]==3 and l[i+1][j+1]==2)
            or
            (l[i][j]==3 and l[i][j+1]==4 and l[i+1][j]==2 and l[i+1][j+1]==1)
            or
            (l[i][j]==2 and l[i][j+1]==3 and l[i+1][j]==1 and l[i+1][j+1]==4)
            or
            (l[i][j]==1 and l[i][j+1]==2 and l[i+1][j]==4 and l[i+1][j+1]==3)
            
             ):
                 a+=1
print(a)
   