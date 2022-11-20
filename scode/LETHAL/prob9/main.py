
T = []

for i in range(2):
    ch = input()
    l = ch.split(' ')
    T.append(l)
time=0
#time+=int(T[0][1])
for i in range (0,int(T[0][0])):
         time+=(int(T[0][1])-(time))
         time+=int(T[0][1])
print( time)       
