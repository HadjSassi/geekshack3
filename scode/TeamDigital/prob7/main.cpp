#include <bits/stdc++.h>
using namespace std;
/*int n //level
int z //number of stars 
int ai //1 stars
int bi //2 stars
int t //minimum number of moves*/

class Solution {
public:
    vector fairCandySwap(vector& A, vector& B) {
        int sumA(0), sumB(0), half;
        unordered_sets;
        for(auto& x: A) sumA += x;
        for(auto& x: B) sumB += x, s.insert(x);
        half = (sumA + sumB) / 2;
        for(auto& x: A) if(s.count(half - (sumA - x))) return {x, half - (sumA - x)};
    }
};

