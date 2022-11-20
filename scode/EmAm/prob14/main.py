try:
  lw=input()
  Tsize=int(input())
  Tnbr=int(input())
  lw1=lw.split()
  l,w=int(lw1[0]),int(lw1[1])
  max_row= l//Tsize
  max_col= w//Tsize
  max = max_col*max_row
  min=Tnbr*2
  if(Tnbr==0):
    min=0
  else:
    if(Tnbr==1):
      min=4
    elif((l%Tsize)>max_row):
      min = min + Tnbr + (max-Tnbr)
  print(min)



  
except:
  print("INPUT_ERROR")