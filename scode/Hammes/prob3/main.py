def Delicious(s1):
    count=1
    s=s1.replace(" ", "")
   
    
    for i in range(0, len(s)):        

        ch=s[i]
        ch1=s
        ch1.replace(ch1[i], '')
        for j in range(i+1, len(s)):
            ch=ch+ch1[j]
            if (ch=='chak') or(ch=='chouka'):
                count=count+1
        
    return(count)    
print(Delicious('chak fssfs chak sfdfsdfcho ukafsddssdfkslflzerzerk chouka sd fsdfsf chak  chouka fsfdsfsdfdsc chak n chouka'))  