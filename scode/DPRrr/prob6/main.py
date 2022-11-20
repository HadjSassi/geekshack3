X=int(input())
bus_num=int(input())
  
bus_meetings=[[]]
for i in range(bus_num):
    bus_meeting = list(map(str, (input().strip().split())))
    bus_meetings.append(bus_meeting)
del bus_meetings[0]

ch=""
profit=0
for i in range(len(bus_meetings)-1):
    t1=bus_meetings[i][1]
    t2=bus_meetings[i+1][1]
    p1=bus_meetings[i][2]
    p2=bus_meetings[i+1][2]
    if (int(t1)<int(t2)) & (int(p1)>int(p2)):
        ch1=bus_meetings[i][0]
        ch+=ch1+" "
        p=int(bus_meetings[i][2])
        profit+=p

import secrets  
L = [i for i in range(len(bus_meetings)-1)]  

while True:
    j = secrets.choice(L)
    k = secrets.choice(L)
    l = secrets.choice(L)
    m = secrets.choice(L)
    if (j!=k)&(j!=l)&(j!=m)&(k!=l)&(k!=m)&(m!=l):
        break
s1=bus_meetings[j][1]
s2=bus_meetings[k][1]
sum = int(s1)+int(s2)
if (sum<X):
    ch1=bus_meetings[j][0] + bus_meetings[k][0]
    ch+=ch1+" "
    p=int(bus_meetings[j][2])+int(bus_meetings[k][2])
    profit+=p
    s3=bus_meetings[l][1]
    sum+=int(s3)
    if (sum<X):
        ch1=bus_meetings[l][0]
        ch+=ch1+" "
        p=int(bus_meetings[l][2])
        profit+=p
        s4=bus_meeting[m][1]
        sum+=int(s4)
        if (sum<X):
            ch1=bus_meetings[m][0]
            ch+=ch1+" "
            p=int(bus_meetings[m][2])
            profit+=p
            
sorted_ch = sorted(ch)
ch = " ".join(sorted_ch)
ch = ch.strip()
print(ch)
print(profit)
  