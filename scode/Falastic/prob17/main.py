inp=input()
liste=[inp]
i=0
s=1
while i<len(liste):
    if "tt" in liste[i]:
        for j in range(0,len(liste[i])):
            if liste[i][j:j+2]=="tt":
                snew=liste[i][0:j]+"v"+liste[i][j+2:]
                if snew not in liste:
                    liste.append(snew)
                    s+=1
            elif ((liste[i])[j:j+2]=="vv"):
                snew1=liste[i][0:j]+"t"+liste[i][j+2:]
                if snew1 not in liste:
                    liste.append(snew1)
                    s+=1
    
    if "vv" in liste[i]:
        for j in range(0,len(liste[i])):
            if liste[i][j:j+2]=="vv":
                snew=liste[i][0:j]+"t"+liste[i][j+2:]
                if snew not in liste:
                    liste.append(snew)
                    s+=1
            elif ((liste[i])[j:j+2]=="tt"):
                snew1=liste[i][0:j]+"v"+liste[i][j+2:]
                if snew1 not in liste:
                    liste.append(snew1)
                    s+=1
    i+=1
print(s)