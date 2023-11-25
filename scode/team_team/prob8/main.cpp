#include <iostream>
#include <vector>
using namespace std;

int main ()
{

    vector<vector <int> > v;
    int n;
    int a,b,c,d,m=0,mi,s=0,si,somme1=0,somme2=0,e=0;
    bool boola;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        vector <int>v2;
        cin >> a;
        e=e+a;

        for(int j=0;j<a;j++)
        {
            cin >> b;
            v2.push_back(b);
        }
        v.push_back(v2);

    }


    for (int j = 0; j < (e/2)+(e %2); j++) {
     for (int i = 0; i < n; i++) {

            c= v[i][0] ;
            if(c>m)
            {
                m=c;
                mi=i;

            }

            d=v[i][v[i].size()-1];
            boola=v[i].size()==1;
            if(d>s)
            {
                if(!((i=mi)||boola)){
                s=d;
                si=i;
                }
            }}
            somme1=somme1+m;
            somme2=somme2+s;
            m=0;s=0;
            if(v[si].size()==1){
            v[si].insert(v[si].begin(), 0);}
            if(v[mi].size()==1){
            v[mi].push_back(0);}
            v[si].pop_back();
            v[mi].erase(v[mi].begin());
            s=0;m=0;

    }
    cout << somme1<<" "<< somme2 ;

    return 0;
}
