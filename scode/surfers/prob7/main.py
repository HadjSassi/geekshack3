import sys
def solve(n, z):
    A = []
    B = []
    for i in range(n):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    summ = 0
    compteur = 0
    while z > 0:
        if z % 2 != 0:
            summ = summ + min(A)
            i = A.index(min(A))
            z-=1
            A[i] = max(A)
        else:
            X=min(A)
            A[A.index(X)]=max(A)
            Y=min(A)
            W=min(B)
            if(W<=X+Y):
                summ+=W
                B[B.index(W)]=max(B)
            else:
                A[A.index(Y)]=max(A)
                summ=summ+Y+X
            z=z-2
    return summ

if __name__ == "__main__":
    n, z = map(int, input().split())
    print(solve(n, z))



