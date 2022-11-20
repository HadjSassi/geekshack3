n=int(input())
T = []
def f1():
 for i in range(2):
    ch = input()
    l = ch.split(' ')
    T.append(l)
 time=0
#time+=int(T[0][1])
 for i in range (0,int(T[0][0])):
         time+=(int(T[0][1])-(time))
         time+=int(T[0][1])
 return time       
s=0
try: 
 for u in range(n):
  s+=f1()
 print(s)
except: print('NO')