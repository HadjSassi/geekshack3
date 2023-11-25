def bounceBall(times=2, feet=10, decreasefactor=0.6): 
    distance=feet 
    for i in range(times): 
        feet*=decreasefactor 
        distance+=2*feet 
    return distance 
 
print(bounceBall())