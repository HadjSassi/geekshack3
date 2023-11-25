Rc=input("")
Rc=Rc.replace(" ","")
Kc=input("")
Kc=Kc.replace(" ","")
Wc=input("")
Wc=Wc.replace(" ","")
colonne_rc=Rc[1]
ligne_rc=Rc[2]
colonne_kc=Kc[1]
ligne_kc=Kc[2]
colonne_wc=Wc[1]
ligne_wc=Wc[2]
if (ligne_rc==ligne_kc and ligne_kc==ligne_wc):
    if(ord(colonne_wc)>ord(colonne_rc)):
        if(ord(colonne_kc)<ord(colonne_wc) and ord(colonne_kc)>ord(colonne_rc)):
            print("NO")
    elif(ord(colonne_wc)<ord(colonne_rc)):
        if (ord(colonne_kc)<ord(colonne_rc) and ord(colonne_kc)>ord(colonne_rc)):
            print("NO")
elif (colonne_rc==colonne_kc and colonne_kc==colonne_wc):
    if (ligne_rc>ligne_wc):
        if(ligne_kc>ligne_wc and ligne_kc<ligne_rc):
            print("NO")
    elif (ligne_rc<ligne_wc):
        if (ligne_kc<ligne_wc and ligne_kc>ligne_rc):
            print("NO")
else:
    print("YES")
