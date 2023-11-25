s=input()
nbcho=0
nbch=0

for i in range(len(s)):
  if s[i:i+5]=='chak':
      nbch+=1
  elif s[i:i+7]=='chouka':
     nbcho+=1
print(min(nbch,nbcho)*2) 