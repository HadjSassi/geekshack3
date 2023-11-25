e=input()

s=e[4:1:-5]

resultat = e.split(" ")
for i in resultat :
    if str(i)==str(i+1):
        print(i)
  
print(s.count(" ")) 