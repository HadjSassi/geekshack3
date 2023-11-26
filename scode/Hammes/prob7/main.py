ch = input()
l = ch.split(" ")

n = int(l[0])
z = int(l[1])

li = []

for i in range(n):
    ch = input()
    l = ch.split(" ")
    li.append([int(l[1]),int(l[0])])


def sortup(l):
    return sorted(l,key=lambda x:x[0])
def sortbotom(l):
    return sorted(l,key=lambda x:x[1])

m = 0
while (z > 1):
    if len(li) > 1:
        if sortup(li)[0][0] <= sortbotom(li)[0][1]+sortbotom(li)[1][1]:
            li =sortup(li)
            m += li.pop(0)[0]
            z=z-2
        else :
            li = sortbotom(li)
            m += li.pop(0)[1]+li.pop(0)[1]
            z=z-2
    
if z==1:
    if sortup(li)[0][0] <= sortbotom(li)[0][1]:
        li =sortup(li)
        m += li.pop(0)[0]
        z=0
    else :
        li = sortbotom(li)
        m += li.pop(0)[1]
print(m)
