dic={1000:"declare_your_position",100:"need_backup",10:"run",1:"take_position"}
# Demande à l'utilisateur d'entrer un nombre
nbr =input()
l=nbr.split()
s=""
l1=[]
try:

    for i in l:
        while(i!=0):
            q=int(i)//2
            res=int(i)%2
            l1.append(res)
            i=q
            l1.reverse()
            str1 ="".join(map(str,l1))

        if len(l1)==2:
            if int(str1) %10==1:
                s=s+dic[10]+' '+dic[1]
                print(s)
            else:
                s=s+dic[10]
                print(s)
        elif len(l1)==3:
            if int(str1)%100==11:
                s=s+dic[100]+' '+dic[10]+' '+dic[1]
                print(s)
            elif int(str1)%100==10:
                 s=s+dic[10]
                 print(s)
            elif int(str1)%100==1:
                s=s+dic[100]+' '+dic[10]
                print(s)
            elif int(str1)%100==0:
                s=s+dic[100]
                print(s)
        elif len(l1)==4:
            if int(str1)%1000==10:
                s=s+dic[100]+' '+dic[10]
                print(s)

except:
    print("NOT_CLEAR")