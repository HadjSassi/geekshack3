def mainFunction(number):
    divisors = []
    for i in range(number, 0,-1):
        if number % i == 0:
            divisors.append(i)
    return divisors
x=int(input(""))
c,s=map(str, input().split())

div=mainFunction(x)
if(c=="E"):
    text=s
    for i in range (0,len(div)):
        t=text[0:div[i]]
        t=t[::-1]
        text=t+text[div[i]:len(text)]
    print(text)
elif(c=="D"):
    text=s
    div.reverse()
    for i in range (0,len(div)):
        t=text[0:div[i]]
        t=t[::-1]
        text=t+text[div[i]:len(text)]
    print(text)
    
        

        
    

