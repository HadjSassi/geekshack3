n=tuple(map(int, input().split()))
roads = [tuple(map(int, input().split())) for _ in range(n[1])]
l=int(input())
count = 0 

d=0
while(True):
    b=l
    for j in range(n[1]):
        s=roads[j]
        if(d==0 and roads[j][1]== n[2]):
            b-=i[1]
            s=i[2]
            d+=1
        if(roads[j][1] == s[0]):
            b-=i[1]
            s=i[2]
        if(b<=0):
            count+=1
            break
print(count)