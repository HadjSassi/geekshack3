while True :
    try:
        b=int(input(""))
        break
    except ValueError:
        print("INPUT_ERROR")
        break
n=int(input(""))
l=[]
for i in range(n):
    x=input()
    l.append(x.split(" "))
