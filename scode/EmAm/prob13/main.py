W=int(input())
n=int(input())
printer=[]
for i in range (0,n) :
    ch=input()
    
    for i in range(0, len(ch.split())):
        printer.append(int(ch.split()[i]))

val=[]
wt=[]

for i in range(0, len(printer),2) : 
    wt.append(printer[i]);
    
    
for i in range(1, len(printer),2) : 
    val.append(printer[i]);
    



def unboundedPrinters(W, n, val, wt):

	
	dp = [0 for i in range(W + 1)]

	ans = 0

	
	for i in range(W + 1):
		for j in range(n):
			if (wt[j] <= i):
				dp[i] = max(dp[i], dp[i - wt[j]] + val[j])

	return dp[W]





print(unboundedPrinters(W, n, val, wt))


  