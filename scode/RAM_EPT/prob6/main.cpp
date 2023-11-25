#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
bool good(int a[], int n){
 for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            return false;
        }
    }

    return true;


}
void findNumbers(vector<int>& ar, int sum,
                 vector<vector<int> >& res, vector<int>& r,
                 int i)
{
    // if we get exact answer
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that
    // have value smaller than sum.
    while (i < ar.size() && sum - ar[i] >= 0) {

        // Till every element in the array starting
        // from i which can contribute to the sum
        r.push_back(ar[i]); // add them to list

        // recursive call for next numbers
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;

        // Remove number from list (backtracking)
        r.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& ar,
                                    int sum)
{
    // sort input array
    sort(ar.begin(), ar.end());

    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, sum, res, r, 0);

    return res;
}


void solve() {
int n;
cin>>n;
char c;
cin>>c;
string ch;
cin>>ch;
vector<int> v;
for (int i = 1; i <= n; i++){
    if (n % i == 0){ v.push_back(i);
    }

}

int sz=v.size();
if(c=='E'){
for(int i=0;i<sz;i++){
    int x=v.back();
    v.pop_back();
    reverse(ch.begin(), ch.begin() + x);



}}
else{
 reverse(v.begin(), v.end());
for(int i=0;i<sz;i++){
    int x=v.back();
    v.pop_back();
    reverse(ch.begin(), ch.begin() + x);



}}
cout<<ch<<endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
