

def knapSack(W, wt, val, n):
    global items
    items=[]
    K = [[0 for w in range(W + 1)]
            for i in range(n + 1)]
             
    
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i - 1] <= w:
                K[i][w] = max(val[i - 1]
                  + K[i - 1][w - wt[i - 1]],
                               K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]
 
   
    global result
    res = K[n][W]
    result=res
     
    w = W
    for i in range(n, 0, -1):
        if res <= 0:
            break
        
        if res == K[i - 1][w]:
            continue
        else:
 
            
            items.append(i-1)
             
            
            res = res - val[i - 1]
            w = w - wt[i - 1]
    


W=int(input())
n=int(input())
printer=[]
for i in range (0,n) :
    ch=input()
    
    
    for i in range(1, len(ch.split())):
        printer.append(int(ch.split()[i]))


val=[]
wt=[]
for i in range(0, len(printer),2) : 
    wt.append(printer[i])
    
    
for i in range(1, len(printer),2) : 
    val.append(printer[i])


knapSack(W, wt, val, n)

items1=items[::-1]
alphabet=['A','B','C','D','E','F']
string=""
for i in items1 :
    string+=alphabet[i]+' '

print(string[:-1])
print(result)


   