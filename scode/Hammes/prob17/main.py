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
i=0
while i<len(ch):
    if i==0:
        ch1=ch.replace("tt","v")
        ch2=ch.replace("vv","t")
        if len(ch1)>0:
            if(search(tab,ch1)):
                tab.append(ch1)
        if(len(ch2))>0:
            if(search(tab,ch2)):
                tab.append(ch2)
    else:
        ch1=ch[0::i+1]+ch[i::].replace("tt","v")
        ch2=ch[0::i+1]+ch[i::].replace("vv","t")
        if len(ch1)>0:
            if(search(tab,ch1)):
                tab.append(ch1)
        if(len(ch2))>0:
            if(search(tab,ch2)):
                tab.append(ch2)
print(tab)
  