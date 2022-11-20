try : 
    c = input()
    if c == "" : 
        print("NO")
except EOFError as e :
    print("NO")