def Comaparer(l1,l2):
     for element1 in l1:
        for element2 in l2:
            if sqrt(pow(element1[0],2)+pow(element1[1],2))>sqrt(pow(element2[0],2)+pow(element2[1],2)):
                return False
     return True  
def territory():
 ns,ms =  input().split()
 n=int(ns)
 m=int(ms)
 l1=[]
 for i in range(n):
        s1,s2 = input().split()
        if s1[0]=='-':
            c1=int(s1[1])
        else:  c1=int(s1[0])
        if s2[0]=='-':
            c2=int(s2[1])
        else:  c2=int(s2[0])
        l11=[c1,c2]
        l1.append(l11) 
 l2=[]
 for i in range(m):
        s1,s2 = input().split()
        if s1[0]=='-':
            c1=int(s1[1])
        else:  c1=int(s1[0])
        if s2[0]=='-':
            c2=int(s2[1])
        else:  c2=int(s2[0])
        l22=[c1,c2]
        l2.append(l22) 
 
 if Comaparer(l1,l2)==True: 
    return 'YES'
 else: return 'NO'
print(territory())
          