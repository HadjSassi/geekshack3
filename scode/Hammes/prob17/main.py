ch=input()
ch1=ch
ch2=""
ch3=""
tab=[ch]
def search(tab,ch):
    for i in tab:
        if(ch==i):
            return False
    return True
for i in ch:
    ch2=ch2+i
    if(ch2=="tt"):
            ch3=ch3+"v"+ch1[2::]
            print(ch3)
            if(search(tab,ch3)):    
                tab.append(ch3)
                tab.append(ch3[::-1])
print(tab)
 