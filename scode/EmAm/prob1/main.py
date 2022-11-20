n=int(input())
words=[]
for i in range (n):
    words.append(input())
    
for word in words:
    num=0
    for i in range (0,len(word)//2):
        if (word[0]==' '):
            word=word[1:]
        l=word[i]
        oppl=word[-i-1]
        if(ord(l)<ord(oppl)):
            while(oppl!=l):
                oppl=chr(ord(oppl)-1)
                num+=1
        else:
            while(oppl!=l):
                l=chr(ord(l)-1)
                num+=1
    print(num)
            