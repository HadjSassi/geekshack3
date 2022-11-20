x=input()
k=x.split(" ")
l=int(k[0])
w=int(k[1])
t_size=int(input())
while True:
    try:
        t_number=int(input())
        break
    except ValueError:
        print("INPUT_ERROR")
        break
s=0
p=0
while l>0:
    s+=1
    l-=(1+t_size)
while w>0:
    p+=1
    w-=(1+t_size)
if t_number <=p*s:
    print(t_number*4)
else:
    print(p*s*4)