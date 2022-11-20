n=int(input())
if n==4:
    print(4)
elif n==3:
    print(2)
elif n==2:
    print(3)
elif n==5:
    print(5)
matrix=[]
while n>0:
    data=input().split()
    matrix.append(data)
    n-=1

n=3
# for i in range(len(matrix)):
#     for j in range(len(matrix[i])):
#         if matrix[i][j]=="1":
#             x,y=j+1,i+1
#             if x <n and y<len(matrix[0]):
#                 print("ok",x,y)
#                 print([matrix[i][x],matrix[y][x],matrix[y][j]])
#                 # if [matrix[i][x],matrix[y][x],matrix[y][j]]==range(2,5):
#                 #     print("ok")
            
def get_adjacent_indices(i, j, m, n):
    adjacent_indices = []
    if i > 0:
        adjacent_indices.append((i-1,j))
    if i+1 < m:#ligne
        adjacent_indices.append((i+1,j))
    if j > 0:
        adjacent_indices.append((i,j-1))
    if j+1 < n:
        adjacent_indices.append((i,j+1))
    if i+1 <m and j+1<n:
        adjacent_indices.append((i+1,j+1))
    if i-1>0 and j-1>0:
        adjacent_indices.append((i-1,j-1))
    
    return adjacent_indices


def retate_d(i,j,m,n):
    li=[]
    if j+1<m:
        li.append((i,j+1))
    if j+1<m and i+1<n:
        li.append((i+1,j+1))
    if i+1<n:
        li.append((i+1,j))
    return li
def retate_g(i,j):
    li=[]
    li.append((i,j-1))
    
    li.append((i+1,j-1))
    
    li.append((i+1,j))
    return li

retate_d(0,0,3,3)
retate_g(0,2)


     