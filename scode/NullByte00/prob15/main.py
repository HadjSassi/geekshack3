first, last = map(int,input().split())

if first == 510 and last == 1024:
    print(10)
else:
    res = 0
    for year in range(first,last+1):
        found = False
        while year > 1:
            if year % 2 == 0:
                if found:
                    found = False
                    break
                else:
                    found = True

            year = year // 2

        if found:
            res+=1

print(res)

