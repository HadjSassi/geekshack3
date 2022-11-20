x=input()
a=x.split(" ")
l=int(a[0])
w=int(a[1])
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
if (t_size*2 + 1 == l):
    if (t_size*2 + 1 < w):
        print(4*t_number)
    else:
        print(3*t_number )
elif (t_size*2 + 1 == w ):
    if (t_size*2 + 1 < l):
        print(4*t_number)
    else:
        print(3*t_number)
elif (t_size * t_number < l*w):
	print(0)
else:
	print(t_number*4)  