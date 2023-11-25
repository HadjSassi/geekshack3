def floorsum(n,m,a,b):
    ret = 0
    while True:
        if a>=m:
            ret += (n-1)*n*(a//m)//2
            a%=m

        if b>=m:
            ret += n*(b//m)
            b%=m

        y = (a*n+b)//m
        x = y*m-b

        if y==0:
            return ret

        ret += (n-(x+a-1)//a)*y
        n = y
        b = (a-x%a)%a
        m,a = a,m

def solve():
    N,ax,bx,ay,by = list(map(int,input().split()))
    if bx == by:
        if ax==ay:
            print(N)
        else:
            print(0)
    else:
        if bx > by:
            ax,ay = ay,ax
            bx,by = by,bx
        D = ay - ax
        l = (D-1)*bx*by//(by - bx) + 1
        if (D+1)*bx*by%(by - bx) == 0:
            r = (D+1)*bx*by//(by - bx) - 1
        else:
            r = (D+1)*bx*by//(by - bx)
        m1 = D*bx*by//(by - bx)
        m2 = D*bx*by//(by - bx) + 1
        #print(D,l,m1,m2,r)
        if 1<=r<=N and 1<=m2<=N:
            ans1 = (r-m2+1)*(D+1) - ((floorsum(r+1,bx,1,0) - floorsum(m2,bx,1,0)) - (floorsum(r+1,by,1,0) - floorsum(m2,by,1,0)))
        elif m2<=N<r:
            r = N
            ans1 = (r-m2+1)*(D+1) - ((floorsum(r+1,bx,1,0) - floorsum(m2,bx,1,0)) - (floorsum(r+1,by,1,0) - floorsum(m2,by,1,0)))
        elif m2>N:
            ans1 = 0
        elif m2<1<=r:
            m2 = 1
            ans1 = (r-m2+1)*(D+1) - ((floorsum(r+1,bx,1,0) - floorsum(m2,bx,1,0)) - (floorsum(r+1,by,1,0) - floorsum(m2,by,1,0)))
        elif r<1:
            ans1 = 0
        if 1<=l<=N and 1<=m1<=N:
            ans2 = (floorsum(m1+1,bx,1,0) - floorsum(l,bx,1,0)) - (floorsum(m1+1,by,1,0) - floorsum(l,by,1,0)) - (m1-l+1)*(D-1)
        elif l<=N<m1:
            m1 = N
            ans2 = (floorsum(m1+1,bx,1,0) - floorsum(l,bx,1,0)) - (floorsum(m1+1,by,1,0) - floorsum(l,by,1,0)) - (m1-l+1)*(D-1)
        elif l>N:
            ans2 = 0
        elif l<1<=m1:
            l = 1
            ans2 = (floorsum(m1+1,bx,1,0) - floorsum(l,bx,1,0)) - (floorsum(m1+1,by,1,0) - floorsum(l,by,1,0)) - (m1-l+1)*(D-1)
        elif m1<1:
            ans2 = 0
        print(ans1 + ans2)
solve() 