def maine():
    try:
        l,w=list(map(int, (input().strip().split())))
        t_size=int(input())
        t_number=int(input())
    except:
        return 'INPUT_ERROR'
    if t_number==0:
        return 0
    if t_number==1 and t_size<min(w,l):
        return 4
    if ((t_number*t_size)+(t_number-1))<11 and t_size<9:
        return 8
    else:
        return t_size*t_number-t_number
    
print(maine())
   