#include <iostream>

using namespace std;

int main()
{
    int arr[] = new int[100];
    int count = 0, max = 0, index;
    int rank[] = {10,7,7,4,10,4};
    char suit[] = {'S','D','C','C','H','D'};
    for(int i = 0 ; i < 100 ; i++) arr[i] = i+1
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
    for(int i=0 ; i<100 ; i++)
        cout<<output[i] << " ";
} 