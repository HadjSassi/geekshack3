print((lambda s, e: sum((c := bin(i).count('0')) == 2 for i in range(s, e + 1)))(*map(int, input().split())))