#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w, h, k, x1, y1, x2, y2, somx = 0;
    cin >> w >> h >> k >> x1 >> y1 >> x2 >> y2;
    char a[w][h];
    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'X')
                somx++;
        }
    int d = abs(x2 - x1), b = abs(y2 - y1);
    float c = d + b;
    
        
   
        cout << ceil(c / k);
}