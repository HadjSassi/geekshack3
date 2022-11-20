import numpy


s=input("")
M = np.zeros(shape=(5,2))

x = s.split()

for i in x:
    i=int(i)

for i in range(5):
    for j in range(5):
        print(M[i][j])

        
