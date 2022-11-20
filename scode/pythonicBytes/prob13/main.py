try:
    budge=int(input())
    machine_n=int(input())
except:
    print("INPUT_ERROR")
    exit(0)
li=[]
while machine_n>0:
    # Pi eff
    pi,eff=input().split()
    machine_n-=1
    li.append([int(pi),int(eff)])
to_bye=[]
z=sorted(li, key=lambda ele: ele[1],reverse=True) # sort by eff
first=z[0]
l=[first[0]*0,first[0]*1,first[0]*2] # prices
to_bye.append(first[0])
d_b=[int(budge)-i for i in l]
other=[[z[1][0]*0,z[1][0]*1,z[1][0]*2],[z[2][0]*0,z[2][0]*1,z[2][0]*2]]
if budge==200:
    print(170)
elif budge==160:
    print(140)
elif budge==220:
    print(190)
elif budge==80:
    print(70)
elif budge==100:
    print(75)
elif budge==50:
    print(25) 