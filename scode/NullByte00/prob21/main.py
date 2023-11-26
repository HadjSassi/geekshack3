n = int(input())

rooms = [list(map(int, input().split())) for _ in range(n)]
hours = 0
for j in range(len(rooms[0])):
    if rooms[0][j] not in [row[j] for row in rooms[1:]]:
        hours += rooms[0][j]

for i in range(1,len(rooms)):
    if(rooms[0][0] - rooms[i][0] == rooms[0][len(rooms[0])-1] - rooms[i][len(rooms[0])-1]):
        if rooms[0][0] % 2 != 0:
            hours+=min(rooms[i][len(rooms[i])-1], rooms[0][0] - rooms[i][0])
        else:
            hours+=rooms[i][len(rooms[i])-1] - (rooms[0][0] - rooms[i][0] + rooms[0][len(rooms[0])-1] - rooms[i][len(rooms[0])-1])
    else:
        hours+=rooms[i][len(rooms[i])-1]
print(hours)



 