ch=input()
D={'{':'}','(':')','[':']'}
D1={}
D2={}
D3={}
L=["'",'"','`']
cho=''
for i in range(len(ch)):
 if ch[i] in D.keys() :
    D1[ch[i]]=i
 elif ch[i] in D.values() :
    D2[ch[i]]=i
 elif ch[i] in L:
    for j in range(i,len(ch)+1) :
      if ch[j]==ch[i] :
        D3[ch[i]]=j
        break
for i in range(len(ch)):
  if ch[i] in D1.keys():
    cho+=ch[D1[ch[i]]:D2[D[ch[i]]]+1]
  elif ch[i] in L :
    cho+=ch[i:D3[ch[i]]]
print(cho)