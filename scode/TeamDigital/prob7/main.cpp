#include <bits/stdc++.h>
using namespace std;
int n //level
int z //number of stars 
int ai //1 stars
int bi //2 stars
int t //minimum number of moves

class Solution {
 public:
  int minMovesToLevel(vector<int>& level, vector<int>& stars) {
    int ans = 0;

    ranges::sort(level);
    ranges::sort(stars);

    for (int i = 0; i < seats.size(); ++i)
      ans += abs(level[i] - stars[i]);

    return ans;
  }
};

 