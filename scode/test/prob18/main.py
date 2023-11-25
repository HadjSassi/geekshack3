N,K = map(int,input().split())
H = list(map(int,input().split()))
H.sort()
print(sum(H[0:N-K]) if N > K else 0) 