ch=input().split()
N=int(ch[0])
F=int(ch[1])
T=int(ch[2])
A=int(ch[3])

class LoL(list):
    def __init__(self, *args):
        list.__init__(self, *args)
    def __getitem__(self, item):
        try:
            return list.__getitem__(self, item)
        except TypeError:
            rows, cols = item
            return [row[cols] for row in self[rows]]



ServStation=[]
Mat1=[]
for i in range (N):
    ServStation.append(input().split())
    
Mat1=[[int(j) for j in e] for e in ServStation]

lol = LoL(Mat1)
depStations=lol[:,0]
depCost=lol[:,1]
retStations=lol[:,2]
retCost=lol[:,3]


Cost=0;
for i in range (1,len(depStations)):
    Cost+=depStations[i]*depCost[i]
   # print (Cost ,depStations[i], depCost[i])

for i in range (0,len(retStations)):
    Cost+=retStations[i]*retCost[i]
   # print (Cost ,retStations[i], retCost[i])
    
#print('abs',abs(T-depStations[0]-F))

Cost=Cost+ abs(T-depStations[0]-F)*depCost[0]-50

print(Cost)


Stops=[]
for i in range (A):
    Stops.append(input().split())
Mat2=[[int(j) for j in e] for e in Stops]
lol = LoL(Mat2)
depTicksN=lol[:,0]
depTicksC=lol[:,1]
retTicksN=lol[:,2]
retTicksC=lol[:,3]

Gain=0;
for i in range (len(depTicksN)):
    Gain+=depTicksN[i]*depTicksC[i]
for i in range (len(retTicksN)):
    Gain+=retTicksN[i]*retTicksC[i]
print(Gain)


print(Gain-Cost)
    
    
    