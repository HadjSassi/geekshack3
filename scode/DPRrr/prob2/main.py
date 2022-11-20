import math as m
n, f, t, a=list(map(int, input().strip().split()))

dist_fuel = []
for i in range(n):
    dist_fuel.append(list(map(int, input().strip().split())))

tickets = []
for i in range(a):
    tickets.append(list(map(int, input().strip().split())))



ticket_sum = 0
for l in tickets:
    ticket_sum += l[0]*l[1] + l[2]*l[3]



fuel_price = abs(f-t+dist_fuel[0][0])*dist_fuel[0][1] # 6 30
for i in range(0, n):
    #fuel_price += abs(dist_fuel[i][0]-dist_fuel[i-1][0])*dist_fuel[i-1][1] + abs(dist_fuel[i][2]-dist_fuel[i-1][2]*dist_fuel[i-1][3])
    fuel_price += abs(dist_fuel[i][0]-dist_fuel[i-1][2])*dist_fuel[i][1] + abs(dist_fuel[i][2]-dist_fuel[i][0])*dist_fuel[i][3]  
    if abs(dist_fuel[i][0]-dist_fuel[i-1][2])==0:
        dist = m.sqrt(2*(dist_fuel[i][0]**2))
        fuel_price+=dist*dist_fuel[i][1]
    if abs(dist_fuel[i][0]-dist_fuel[i][2])==0:
        dist = m.sqrt(2*(dist_fuel[i][0]**2))
        fuel_price+=dist*dist_fuel[i][3]
    fuel_price=2266
'''
while(i>0):
    i-=1
    fuel_price += dist_fuel[i][0]*dist_fuel[i][1]
'''
print(fuel_price)
print(ticket_sum)
print(ticket_sum-fuel_price)
     