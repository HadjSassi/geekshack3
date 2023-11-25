import sys
def min_after_x(A,x):
    minn=A[0]
    for i in range(len(A)):
        if(A[i]<minn) and (A[i]!=x):
            minn=A[i]
    return minn
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
            A.remove(A[i])
        else:
            if(A!=[]):
                X=min(A)
                Y=min_after_x(A,X)
            if(B!=[]):
                W=min(B)
            if(W<=X+Y):
                summ+=W
                B.remove(W)
            else:
                print(X)
                A.remove(Y)
                summ=summ+Y+X
            z=z-2
    return summ

if __name__ == "__main__":
    n, z = map(int, input().split())
    print(solve(n, z))



