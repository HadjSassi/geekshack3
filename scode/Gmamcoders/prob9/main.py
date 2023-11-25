n, m = map(int, input().split())
La=[]
Li=[]
k=0
for i in range(n):
    Ax,Ay=map(int, input().split())
    La.append((Ax,Ay))
for i in range(m):
    Ix,Iy=map(int, input().split())
    Li.append((Ix,Iy))
for i in La:
    for j in Li:
        if i==j:
            print("YES")
            k=1
            break

if k==0:
    print('NO')
 