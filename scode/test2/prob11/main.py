a,b = map(int,input().split())
count=0
for i in range(0,65):
	for j in range(0,i-1):
		if a<=(2**i-1)-2**j<=b:
			count+=1
print(count)   