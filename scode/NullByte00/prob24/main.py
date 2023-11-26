N,A,xa,B,xb=map(int,input().split())
s=0
for i in range(1,N+1):
    if A+i//xa==B+i//xb:
        # print(i)
        s+=1
print(s)