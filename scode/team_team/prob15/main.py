input=input()
l=input.split(" ")
x=int(l[0])
y=int(l[1])

ch=""
sum=0
for i in range(x,y,1):
  ch=str(bin(i))
  if (ch[1:].count('0'))==1:
      sum+=1
      
print(sum)