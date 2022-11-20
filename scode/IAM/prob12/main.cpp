#include <iostream>
#include <functional>
using namespace std;
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

void integer(string a)
{
    if (!isNumber(a))
        cout<<"INPUT_ERROR\n";
}
int main()
{
    string Nb_L, Nb_c,Pos_Gx, Pos_Gy, Pos_Px, Pos_Py,Nb_obstacle;

    cin>> Nb_L;
    integer(Nb_L);

    cin>> Nb_c;
    integer(Nb_c);

    cin>> Pos_Gx;
    integer(Pos_Gx);

    cin>>  Pos_Gy;
    integer( Pos_Gy);

    cin>> Pos_Px;
    integer(Pos_Px);

    cin>> Pos_Py;
    integer(Pos_Py);

    cin>> Nb_obstacle;
    integer(Nb_obstacle);



    string m1,m2;
    int b = stoi(Nb_obstacle);
    string t[b];

    for(int i=0; i<b; i++)
    {
        cin>>m1;
        integer(m1);
        cin>>m2;
        integer(m2);
        t[i] = m1+m2;
    }
    auto checkNeighbors =[&]()
    {
        int b_x, b_y;
        int G_x = stoi(Pos_Gx);
        int G_y = stoi(Pos_Gy);
        int Temp_x=0;
        int Temp_y=0;
        int Temp_short=	9999999;
        Pos_Py = stoi(Pos_Py);
        Pos_Px = stoi(Pos_Px);
        Nb_c = stoi(Nb_c);

        auto check =[&]()
        {
            if (abs (G_x - Pos_Px) + abs (G_y - Pos_Py) < Temp_short && (G_x < Nb_c || G_x > 0 || G_y < Nb_L || G_y > 0) )
            {
                string s;
                to_string(G_x);
                to_string(G_y);
                s=G_x+G_y;
                for(int i=0; i<b; i++)
                {

                if(s==t[i])
                {
                    Temp_x = G_x;
                    Temp_y = G_y;
                    Temp_short=abs (G_x - Pos_Px) + abs (G_y - Pos_Py) ;
                }
                 }
            };
            auto checkY [*]()
            {
                G_y--;
                check();
                G_y++;
                check();
                G_y++;
                check();
            };
            G_x--;
            checkY();
            G_x++;
            checkY();
            G_x++;
            checkY();
            if(Temp_x==0)
            {
                return FALSE;
            }
            else
            {
                Pos_Gx=Temp_x;
                Pos_Gy=Temp_y;
                steps++;
                return TRUE;
            }
        }

        int shortest = abs (Pos_Gx - Pos_Px) + abs (Pos_Gy - Pos_Py);
        while (i > 0 && abs (Pos_Gx - Pos_Px) + abs (Pos_Gy - Pos_Py) > 0)
        {
            checkNeighbors();
            i--;
        };
        if(abs (Pos_Gx - Pos_Px) + abs (Pos_Gy - Pos_Py) > 0)
        {
            cout "0";
        }
        else
        {
            cout steps;
        }

        return 0;
    }
