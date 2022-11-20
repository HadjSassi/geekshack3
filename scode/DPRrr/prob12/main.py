# import numpy as np
from math import *

def trapped(mat_pic, nb_l, nb_c, pos_gx, pos_gy, pos_px, pos_py, obstacles_list):
    limit_list=[]
    
    for i in range(pos_gx-1, pos_gx+2):
        for j in range(pos_gy-1, pos_gy+2):
            if i>=0 and i<nb_l and j>=0 and j<nb_c and mat_pic[i][j]!=1:
                limit_list.append(mat_pic[i][j])
    return limit_list == [3.0]*len(limit_list)
    

def main():
    try:
        nb_l, nb_c = list(map(int, input().strip().split()))
        pos_gx, pos_gy, pos_px, pos_py = list(map(int, input().strip().split()))
        nb_obstacle = int(input().strip())
        obstacles_list = []
        for o in range(nb_obstacle):
            obstacles_list.append(tuple(map(int, input().strip().split())))
    
        #mat_pic = np.zeros((nb_l, nb_c))
        mat_pic = [[0.0]*nb_l for i in range(nb_c)]

        mat_pic[pos_gx][ pos_gy] = 1 # ghost
        mat_pic[pos_px][ pos_py] = 2 # player
        for t in obstacles_list:
            mat_pic[t[0]][t[1]] = 3 # obstacle
    
    except:
        return('INPUT_ERROR')

    if trapped(mat_pic, nb_l, nb_c, pos_gx, pos_gy, pos_px, pos_py, obstacles_list) :
        return 0
    if nb_obstacle == 0:
        return int(sqrt(abs(pos_gx-pos_px)**2+abs(pos_gy-pos_py)**2)//sqrt(2))

        
    if pos_gx == pos_px:
        pas = 0
        while pos_py != pos_gy:
            if (pos_gx, pos_gy-1) not in obstacles_list:
                pas+=1
                pos_gy-=1
            else:
                pos_gy -= 2
                pas+=2
        return pas
    
    else:
        pas = 0
        while pos_py != pos_gy:
            if (pos_gx+1, pos_gy-1) not in obstacles_list:
                pas+=1
                pos_gy-=1
                pos_gx+=1
            else:
                pos_gy -= 2
                pos_gx += 1
                pas+=2
        while pos_px != pos_gx:
            if (pos_gx+1, pos_gy) not in obstacles_list:
                pas+=1
                pos_gx+=1
            else:
                pos_gx += 2
                pas+=2
        return pas
    
        
                    
        #pas = 0
        #while pos_gx != pos_px and pos_py != pos_gy:
            
        

print(main())
