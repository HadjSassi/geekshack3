nbmot = int(input())

def notPalindrome(ch):
    
    if(ch==ch[len(ch)::-1]):
        return False
    return True

listMot=[]
for i in range(nbmot):
    listMot.append(input())

ch=""
for x in listMot:
    count=0
    while(notPalindrome(x) and count<21):
        for i in range(len(x)//2):
            if(x[i]>x[len(x)-i-1]):
                a=chr(ord(x[len(x)-i-1])+1)
                
                x=x[:len(x)-i-1]+a+x[len(x)-i:]
                #print(x)
                count+=1
            elif (x[i]<x[len(x)-i-1]):
                
                a=chr(ord(x[len(x)-i-1])-1)
                
                x=x[:len(x)-i-1]+a+x[len(x)-i:]
                #print(x)
                count+=1
    print(count)
             
        



    