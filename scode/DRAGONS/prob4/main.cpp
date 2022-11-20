//
// Created by CHAABANE IHEB on 27/11/2021.
//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
// Dimensions of paint screen
#define M 7
#define N 7
int graph[N][M];

// A recursive function to replace previous color 'prevC' at  '(x, y)'
// and all surrounding pixels of (x, y) with new color 'newC' and
void floodFillUtil( int x, int y, int prevC, int newC)
{
    // Base cases
    if (x < 0 || x >= N || y < 0 || y >= M)
        return;
    if (graph[x][y] != prevC)
        return;
    if (graph[x][y] == newC)
        return;

    // Replace the color at (x, y)
    graph[x][y] = newC;

    // Recur for north, east, south and west
    floodFillUtil( x+1, y, prevC, newC);
    floodFillUtil( x-1, y, prevC, newC);
    floodFillUtil( x, y+1, prevC, newC);
    floodFillUtil( x, y-1, prevC, newC);
}

// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void floodFill( int x, int y, int newC)
{
    int prevC = graph[x][y];
    if(prevC==newC) return;
    floodFillUtil( x, y, prevC, newC);
}

// Driver code
int main() {

    int n;
    cin >> n;
    if (feof(stdin)) {
        cout << "NO";
    } else {
        //int graph[n][7];
        memset(graph, 0, sizeof(graph));
        cin.tie();
        cin.ignore();
        string s;
        int j = 0;
        while (n--) {
            int nb=0;
            getline(cin, s);
            for (int i = 0; i < s.length(); i++) {
                if (s[i]=='S') {
                    graph[j][i-nb] = 1;
                } else if (s[i] == 'T') {
                    graph[j][i-nb] = 2;
                }
                else if(s[i]==' ')
                    nb++;
            }
            j++;
        }
        //floodFillUtil(0,3,1,2);
        int l = 3;
        int b=4;
        for (int i = 0; i < 7; i++) {
            for (int k = 0; k < 7; k++) {
                if (graph[i][k] == 1) {
                    floodFillUtil(i, k, 1, l);
                    l += 2;
                } else if (graph[i][k] == 2) {
                    floodFillUtil(i, k, 2, b);
                    b += 2;
                }
            }
        }
        vector<int> vs((l - 2)/2, 0);
        vector<int> vt((b-4)/2,0);
        for (int e =3; e < l; e+=2) {
            for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                    if (graph[i][j] == e) {
                        vs[e/2 -1]++;
                    }
                }
            }
        }
        for (int e =4; e < b; e+=2) {
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 7; j++) {
                        if (graph[i][j] == e) {
                            vt[(e-4)/2]++;
                        }
                    }
                }
            }
        sort(vs.begin(), vs.end());
        cout<<'S'<<" ";
        for (int i=0;i<vs.size();i++) {
            if(i==vs.size()-1)
                cout<<vs[i]*100;
            else
            cout << vs[i] * 100 << " ";
        }
        cout<<endl;
        sort(vt.begin(),vt.end());
        cout<<"T"<<" ";
        for (int i=0;i<vt.size();i++) {
            if(i==vt.size()-1)
                cout<<vt[i]*100;
            else
                cout << vt[i] * 100 << " ";
        }
        cout<<endl;


       /* cout << "Updated screen after call to floodFill: \n";
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }*/
    }
}
