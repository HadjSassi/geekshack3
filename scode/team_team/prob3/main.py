s=input()
som=0


for i in range(len(s)-6):
  if s[i:i+5]=='chak':
     som+=s[i+5:].count('chouka')
  
print(som)  