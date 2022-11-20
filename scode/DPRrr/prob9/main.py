try:
 
    
        push, time = map(int, input().strip().split())
        push_times = list(map(int, input().strip().split()))


        use = time
        for i in range(1, len(push_times)):
            use += min(push_times[i]-push_times[i-1], time)

        print(use)
        
except: print('NO')