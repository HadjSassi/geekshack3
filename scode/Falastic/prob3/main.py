c=input()
c.lower()
c=c.replace(" ","")
chackchouka=c.count("chakchouka")
chack=c.count("chak")-chackchouka
chouka=c.count("chouka")-chackchouka
print(min(chack,chouka)*2+chackchouka*3)
 