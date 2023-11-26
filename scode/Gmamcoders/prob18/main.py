
n = int(input())
L= list(map(int, input().split()))
k=0
i=0
while(i<n-2):
    if (L[i]==L[i+2]) and ((L[i]!=L[i+1])or( L[i+2]!=L[i+1])):
        k=k+1
    i=i+2
print(k)
