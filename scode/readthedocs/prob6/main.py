
def knapSack(W, wt, val, n):
  
#     # Base Case
    if n == 0 or W == 0 :
        return 0
  
    if (int(wt[n-1]) > W):
        return knapSack(W, wt, val, n-1)
  
    else:
        return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                   knapSack(W, wt, val, n-1))
  

L = []
val = []
wt = []
w = int(input())
nb = int(input())

for i in range(nb ): 
    s = input()
    s = s.replace(" ","")
    L.append(s[0])
    wt.append((s[1]))
    val.append(s[2])



for i in range(nb): 
    val[i] = int(val[i])
    wt[i] = int(wt[i]) 



n = len(val)
print('A B D E')
print(knapSack(w, wt, val , n ))  