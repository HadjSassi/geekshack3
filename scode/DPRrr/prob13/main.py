def main():
    try:
        b = int(input())
        n = int(input())
        prod_list = []
        for i in range(n):
            prod_list.append(list(map(int, input().strip().split())))
        
        max_effic = 0
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    price = prod_list[0][0]*i+prod_list[1][0]*j+prod_list[2][0]*k
                    effic = prod_list[0][1]*i+prod_list[1][1]*j+prod_list[2][1]*k
                    if price <= b and effic > max_effic:
                        max_effic = effic
        return max_effic
        
        
        
    except:
        return 'INPUT_ERROR'

print(main())
 