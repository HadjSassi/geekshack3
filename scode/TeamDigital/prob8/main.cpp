#include <iostream>

using namespace std;

int main()
{
    int n = 6;
    int output[n];
    int count = 0, max = 0, index;
    int rank[] = {10,7,7,4,10,4};
    char suit[] = {'S','D','C','C','H','D'};
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (rank[j] > max)
            {
                max = rank[j];
                index = j;
            }
        }
        output[count]= index;
        count++;
        rank[index]=0;
        max=0;
    }
    for(int i=0 ; i<n ; i++)
        cout<<output[i] << " ";
}