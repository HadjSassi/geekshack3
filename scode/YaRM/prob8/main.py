def largestRectangle():
    try:
        n=4
        ch= input()
        try: 
           n=len(h)
        except:
            if(n<4):
                print("NO")
        h = list(map(int, ch.strip().split(' ')))
        res = 0
        for i in range(n):
             length = 0
             for j in range(i, -1, -1):
                   if h[j] >= h[i]:
                         length += 1
                   else:
                        break
                
        for j in range(i+1, n):
            if h[j] >= h[i]:
                length += 1
            else:
                break
        
        res = max(res, length*h[i])
        print(res)    
    except:
        print('NO')

largestRectangle()  