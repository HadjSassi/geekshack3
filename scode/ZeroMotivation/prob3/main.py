s = input()
nb = 0
s = s.strip()

if len(s) < 10 :
    print(0)
else :
    
    for i in range (len(s) - 4) :
        
        if s[i:i+4] == "chak" :
            for j in range(i+4,len(s)) :
                if s[j:j+6] == "chouka" :
                    nb += 1

    print(nb)