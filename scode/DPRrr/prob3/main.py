def main():
    try:
        N=int(input())
        l=[]
        for i in range(N):
            l.append(list(map(int, (input().strip().split()))))

        ma=0
        for i in (l):
            if max(i)>ma:
                ma=max(i)

        li=[]
        for i in range(N):
            lis=[]
            for j in range(ma+1):
                lis.append(0)
            li.append(lis)


        for i in l:
            for j in i:
                li[l.index(i)][j]=1

        # li
        l=[]
        #debut
        lscore = []
        score= 0
        for l1 in li:
            j=0
            while(j<len(i)):
                if l1[j] == 0: 
                    j+=1
                    score = 0
                    continue
                #elif j == len( 
                elif l1[j] == 1:
                    while l1[j]==1:
                        score += 100
                        j+=1
                    lscore.append(score)
        lscore.append(100)
                
        lscore.sort()
        return lscore
        #fin
        """test_contour = True
        for i in range(len(li)):
            if i == 0 and li[i] != [1]*len(li[i]): test_contour = False
            elif  i == len(li)-1 and li[i] != [1]*len(li[i]): test_contour = False
            
            elif li[i][0] == 0 and  li[i][len(li)-1] == 0: test_contour = False
            
            elif 0 in li[i] : test_contour = False
        if not test_contour:
            return [100*((len(li[0])+len(li))*2-4)]
        
        """ 
            
        
        
        
        """lscore = []
        score= 0
        for l1 in li:
            j=0
            while(j<len(i)):
                if l1[j] == 0: 
                    j+=1
                    score = 0
                    continue
                #elif j == len( 
                elif l1[j] == 1:
                    while l1[j]==1:
                        score += 100
                        j+=1
                    lscore.append(score)
        lscore.append(100)
                
        lscore.sort()
        return lscore
        #for i in lscore:
        #    print(i)"""
                    
                
        
        
        
        
    except:
        try:
            test_contour = True
            for i in range(len(li)):
                if i == 0 and li[i] != [1]*len(li[i]): test_contour = False
                elif  i == len(li)-1 and li[i] != [1]*len(li[i]): test_contour = False
            
                elif li[i][0] == 0 and  li[i][len(li)-1] == 0: test_contour = False
            
                elif 0 in li[i] : test_contour = False
            if not test_contour:
                return [100*((len(li[0])+len(li))*2-4)]
        except:
           return['NO']
l=main()
for i in l:
    print(i)
     