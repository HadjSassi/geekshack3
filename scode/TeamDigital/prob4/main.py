DH= int(input("Enter Drop Height: "))
BI=float (input("Enter Bounce Index: "))
BN=int (input("Enter Number of Bounces: "))
TDT= 
for x in range (BN):
    TDT+= DH+(BI*DH)
    DH  =(BI*DH)
    print ("Total distance traveled : ",TDT)