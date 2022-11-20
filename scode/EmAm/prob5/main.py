

import sys
try:
    x=input()
except EOFError:
    print('NO')
    sys.exit()
    

n = int(x)
lines = []
Main = []
A=[]
B=[]
for i in range (0,n) :
    ch=input()
    lines.append(ch.split())


for line in lines: 
    if ( line[1]=='Main'):
        Main.append(line[2:])
    elif ( line[1]=='A'):
        A.append(line[2:])
    else: 
        B.append(line[2:])

def merge (list1, list2):
    newlist = []
    newlist = list1 +list2
    final = sorted(newlist)
    return final
    
def findElem(e, list1):
    for i in list1:
        for j in i:
            if (j==e):
                return i
                break 



            
finalMain=[]
Uploaded=[]
Modified=[]
StillInMain=[]
FoundInMain=[]


for elem in A : 
    if (elem in Main) : 
        FoundInMain.append(elem)
        Main.pop(Main.index(elem))
        A.pop(A.index(elem))
for elem in B : 
    if (elem in Main) : 
        FoundInMain.append(elem)
        Main.pop(Main.index(elem))
        B.pop(B.index(B))
 

 
#Modified#       
for elem in A: 
    for e in elem: 
         if ( any(e in sublist for sublist in Main) == True ):
             eleminMain= findElem(e, Main)
             Main.pop(Main.index(eleminMain))
             A.pop(A.index(elem))
             final=merge(elem, eleminMain)
             res = []
             [res.append(x) for x in final if x not in res]
             Modified.append(res)

for elem in B: 
    for e in elem: 
         if ( any(e in sublist for sublist in Main) == True ):
             eleminMain= findElem(e, Main)
             Main.pop(Main.index(eleminMain))
             B.pop(B.index(elem))
             final=merge(elem, eleminMain)
             res = []
             [res.append(x) for x in final if x not in res]
             Modified.append(res)
#end Modified
             

 
#uploaded
for elem in A :
    if elem not in Main : 
        Uploaded.insert(0,elem)
        A.pop(A.index(elem))
        
for elem in B :
    if elem not in Main : 
        Uploaded.insert(0,elem)
        B.pop(B.index(elem))
#end Uploaded

#what's more in main 

if (Main):
    for elem in Main:
        StillInMain.append(elem)
        Main.pop(Main.index(elem))

#end what's more in main 



def toString(list1):
    ModifiedList=""
    for e in list1: 
        stringElem = ' '.join(map(str,e))
        ModifiedList+=stringElem + " "
    return ModifiedList


if(Modified):
    for e in Modified:
        finalMain.append(toString(e) + ": M")
Uploaded1=Uploaded[::-1]
if(Uploaded1):
    for e in Uploaded1:
        finalMain.append(toString(e) + ": U")

if(StillInMain):
    for e in StillInMain:
        if (e!=[]):
            finalMain.append(toString(e)[:-1])
    
if(FoundInMain):
    finalMain.append(toString(FoundInMain)[:-1])




for e in finalMain:
    print(e)


        
        

    
   