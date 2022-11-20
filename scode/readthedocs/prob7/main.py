import re 
s = input()

L = ['(',')','{','}','\'' ,'"', "`",'[',']' ]

def occ(): 
    occ = 0 
    for i in range(len(L)): 
        if s.find(L[i]) != None : 
            occ += 1 
    if occ <= 2 : 
        print( 'SYNTAX_ERROR'  )

    return re.search(r'\[(.*?)\]',s).group()

print(occ())