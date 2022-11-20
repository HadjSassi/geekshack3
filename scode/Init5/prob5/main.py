try:

    modified = []
    updated = []
    same = []
    main = set()
    n = int(input())
    for i in range(n):
        x = input().split()
        if(len(x) == 2): continue
        if(x[1] == 'Main'):
            main.add("".join(x[2:]))
        else:
            s = "".join(x[2:])
            found_all = False
            found_part = False 
            for item in main:
                if(s == item): found_all = True 
                elif s[0] == item[0]: found_part = True 
            if found_all:
                same.append(s)
            elif found_part:
                modified.append(s)
            else: updated.append(s)
        
    for item in modified:
        for c in item:
            print(c, end = " ")
        print(": M")
    
    for item in updated:
        for c in item:
            print(c, end = " ")
        print(": U")
    
    for item in same:
        n = len(item)
        for i in range(n):
            if(i == n - 1):
                print(item[i])
            else:
                print(item[i], end=" ")


    for a in main:
        unique = True
        for b in same:
            if(a[0] == b[0]):
                unique = False 
        for b in modified:
            if(a[0] == b[0]):
                unique = False

        if(unique):
            n = len(a)
            for i in range(n):
                if(i == n - 1):
                    print(a[i])
                else:
                    print(a[i], end=" ")
        

except:
    print("NO")
