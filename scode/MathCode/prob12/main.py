(Nb_L, Nb_c)=(input("donner le nombre des lignes"),input("donner le nombre des colones"))
(Pos_Gx, Pos_Gy , Pos_Px , Pos_Py)=(input("donner la valeur Pos_Gx"),input("donner la Pos_Gy"),input("donner Pos_Px"),input("donner Pos_Py"))
nb_obstacle=input("donner le nombre d'obstacle")
L=[]
for i in range(int(nb_obstacle)):
    (x,y)=(input("donner l'abscisse de l'obstacle"),input("donner l'ordonné de l'obstacle"))
    L.append((x,y))  