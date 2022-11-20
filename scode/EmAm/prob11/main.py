import sys 
ch=input()
test= True
for i in range(0,len(ch)):
    if (  (ord(ch[i]) not in range (48,58)) and ( ord(ch[i])!=32) ): 
        print('NOT_CLEAR')
        test=False
        sys.exit()

binList=[]

if (test==True): 
    
   
    for i in ch.split():
        if (i!=' '):
            binaryI=bin(int(i))
           
            binaryInt=int(binaryI[binaryI.find('b')+1:])
            binList.append(binaryInt)


binList2=[]
for i in binList:
    j=i
    while (j-1000 >0):
        binList2.append(i-1000)
        binList2.append(1000)
        binList.pop(binList.index(i))
        j = j-1000
        
binList=binList+binList2

binList3=[]
for i in binList:
    j=i
    if(i!=1000):
        while (j-100 >0):
            binList3.append(i-100)
            binList3.append(100)
            binList.pop(binList.index(i))
            j = j-100

binList=binList+binList3

binList4=[]
for i in binList:
    j=i
    if(i!=100 and i!=1000):
        while (j-10 >0):
            binList4.append(i-10)
            binList4.append(10)
            binList.pop(binList.index(i))
            j = j-10

binList=binList+binList4



binList.sort(reverse=True)

for e in binList:
    if (e==1):
        if (binList.index(e)==0):
            print('take_position', end = '')
        else:
            print(' take_position', end = '')
    if (e==10):
        if (binList.index(e)==0):
            print('run', end = '')
        else:
            print(' run', end = '')
    if (e==100):
        if (binList.index(e)==0):
            print('need_backup', end = '')
        else:
            print(' need_backup', end = '')
    if (e==1000):
        if (binList.index(e)==0):
            print('declare_your_position', end = '')
        else:
            print(' declare_your_position', end = '')







        

 