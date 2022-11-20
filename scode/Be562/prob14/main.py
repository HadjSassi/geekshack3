ch=input()
l1=ch.split()
for i in range(2):
    if not l1[i].isnumeric():
        print("INPUT_ERROR")
        quit()
    
    l1[i]=int(l1[i])
s=input()
n=input()
if not s.isnumeric() or not n.isnumeric():
    print("INPUT_ERROR")
    quit()
s=int(s)
n=int(n)
surftot=l1[1]*l1[0]
surftb=n*s**2
if surftot>(surftb+4*n*s+4*n):
    print (4*n)
elif surftb>surftot:
    print(0)
else:
    print((surftot-surftb)%(surftb))
       