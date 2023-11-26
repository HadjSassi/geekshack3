s = "tttt"
d=len(s)
s2=""
for k in range(d):
  i=s.count('tt')
  i1=s.count("ttt")
  j=s.count('vv')
  j1=s.count("vvv")

 
  if "tt" in s:
     s1=s.replace('tt','v')
  i2=s1.count('tt')
  i3=s1.count("ttt")
  j2=s1.count('vv')
  j3=s1.count("vvv")
  
  if "vv" in s:
    s2=s.replace('vv','t')
  e=s2.count('tt')
  e1=s2.count("ttt")
  e2=s2.count('vv')
  e3=s2.count("vvv")

  
som=i+i1+i2+i3+j+j1+j2+j3+e+e1+e2+e3+2
print(som)
 