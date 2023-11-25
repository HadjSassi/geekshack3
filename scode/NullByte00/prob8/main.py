from collections import deque

n = int(input())
stacks=[]
for i in range(n):
    s = input()
    m = int(s[0])
    stacks.append(list(map(int, s[2:].split())))


turns = 0
for stack in stacks:
    turns+=len(stack)

score1=score2=0
i=0
while i < turns:
    if i % 2 == 0:
        mx = 0
        loc = 0
        for index,stack in enumerate(stacks):
            if stack and stack[0] > mx:
                mx = stack[0]
                loc = index
        
        score1+=stacks[loc].pop(0)
    else:
        mx = 0
        loc = 0
        for index,stack in enumerate(stacks):
            if stack :
                if stack[len(stack)-1] > mx:
                    mx = stack[len(stack)-1]
                    loc = index
        
        score2+=stacks[loc].pop(len(stacks[loc])-1)
    
    i+=1
print(score1,score2)



