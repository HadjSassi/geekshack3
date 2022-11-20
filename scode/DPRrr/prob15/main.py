mat = []
for i in range(int(input())):
    mat.append(list(map(int, input().strip().split())))

n = 0
for i in range(len(mat)-1):
    for j in range(len(mat[0])-1):
        #mat1 = mat[i:i+2][j:j+2]
        l1 = [mat[i][j], mat[i+1][j], mat[i+1][j+1], mat[i][j+1]]
        
        if 1 in l1 and 2 in l1 and 3 in l1 and 4 in l1 and abs(l1[2]-l1[0]) == 2 and abs(l1[1]-l1[3]) ==2:
            n+=1

print(n)

