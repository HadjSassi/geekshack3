try:
    valu = int(input())
except:
    print('NO')
    exit(0)
ligne=valu
_inp_max=[]
_inp_vmax=[]
j=0
while valu>0:
    poss = input().split()
    _inp_max.append([j,poss])
    _inp_vmax.extend(poss)
    
    valu-=1
    j+=1
_max_el=max(_inp_vmax)

matrix=[[0 for k in range(int(_max_el)+1)] for i in range(ligne)]

for i in range(ligne):
    v=[]
    matrix[i]=[0 if str(k) not in _inp_max[i][1] else 1 for k in range(int(_max_el)+1)]

# print(matrix)
c=[]
for li in matrix:
    c.append(str(len([i for i in li if i==1])*100))
c=sorted(c)
for x in c:
    print(x)