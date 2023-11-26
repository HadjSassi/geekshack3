#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

struct particle{
    double x;
    double y;
    double z;
};

//this function checks wether a chosen sphere u overlaps with any other sphere
bool overlap(vector<particle> pos, size_t u, const double R, double L){

    double rx, ry, rz;

    for(size_t j=0; j<pos.size(); j++){
        if(u==j) continue;
        //calculate shortest distance between spheres (periodic boundaries!)
        rx=abs(pos.at(u).x-pos.at(j).x);
        ry=abs(pos.at(u).y-pos.at(j).y);
        rz=abs(pos.at(u).z-pos.at(j).z);
        if(rx>0.5) rx=1-rx; //periodic boundaries
        if(ry>0.5) ry=1-ry;
        if(rz>0.5) rz=1-rz;

        if(rx*rx+ry*ry+rz*rz < 4*(R/L)*(R/L)){
            return true;
        }
    }
    return false;
}
