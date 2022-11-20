class ObjetSac: 
    def __init__(self, poids, valeur, indice): 
        self.indice = indice         
        self.poids = poids 
        self.valeur = valeur
        self.rapport = valeur // poids 
       
  #Fonction pour la comparaison entre deux ObjetSac
  #On compare le rapport calculé pour les trier
    def __lt__(self, other): 
        return self.rapport < other.rapport 
    def __lt1__(self, other): 
        return self.rapport1 < other.rapport1 

def getValeurMax(poids, valeurs, capacite): 
        tableauTrie = [] 
        for i in range(len(poids)): 
            tableauTrie.append(ObjetSac(poids[i], valeurs[i], i)) 
  
        #Trier les éléments du sac par leur rapport
        tableauTrie.sort(reverse = True) 
  
        compteurValeur = 0
        for objet in tableauTrie: 
            poidsCourant = int(objet.poids) 
            valeurCourante = int(objet.valeur) 
            if capacite - poidsCourant >= 0: 
                #on ajoute l'objet dans le sac
                #On soustrait la capacité
                capacite -= poidsCourant 
                compteurValeur += valeurCourante
                #On ajoute la valeur dans le sac 
            else: 
                fraction = capacite / poidsCourant 
                compteurValeur += valeurCourante * fraction 
                capacite = int(capacite - (poidsCourant * fraction)) 
                break
        return int(compteurValeur) 



capacite=10
n=int(input())
poids=[4,2,9,4,6]
valeurs=[12,16,7,3,5]


valeurMax = getValeurMax(poids, valeurs, capacite) 
print ("A B D")  
print(valeurMax)  





    