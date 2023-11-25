def polynomial(coefs,vals):
    coefs=coefs[::-1]
    l=[]
    for val in vals:
        s=0
        for i in range(len(coefs)):
            # print(i)
            s+=coefs[i]*val**(i)
        l.append(str(s))
    return l

for _ in range(int(input())):
    coefs = [int(i)  for i in  input().split()]
    vals = [int(i)  for i in  input().split()]
    print(" ".join(polynomial(coefs,vals)))
 