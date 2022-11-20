
try : 
    L , W = input().strip().split(" ")
    L , W = int(L) , int(W)
    T_size = int(input())
    T_number = int(input())
except ValueError as e: 
    print('INPUT_ERROR')


# room = [[0 for i in range(L)] for j in range(W)]
# table = [[1 for i in range(T_size)] for j in range(T_size)]

def fitTable(): 
    if T_number == 0 : 
        k =  0 
    # if W - 2*T_size > 3 and L - T_size > 2 : 
    #     k = 8 
    # elif W - 2* T_size == 2 and L - T_size > 2 : 
    #     k = 6 
    # elif W - 2*T_size == 1 and L - T_size > 2 : 
    #     k = 5 
    # elif W - 2*T_size <= 0 and L - T_size > 2 : 
    #     k = 4 
    return k    


print(fitTable()) 