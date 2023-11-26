#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

#define for_range(a) for (int i = 0; i < (a); i++)

// Forward declarations for printing data structures
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec);

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &arr);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::queue<T> &q);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::stack<T> &s);

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::map<K, V> &m);

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<K, V> &um);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s);

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &us);

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::pair<K, V> &um);

// Macro to print variables
#define print(args...)                               \
    {                                                \
        std::string _s = #args;                      \
        replace(_s.begin(), _s.end(), ',', ' ');     \
        std::stringstream _ss(_s);                   \
        std::istream_iterator<std::string> _it(_ss); \
        pr(_it, args);                               \
    }

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    os << "[";
    if (!vec.empty())
    {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
        {
            os << ", " << vec[i];
        }
    }
    os << "]";
    return os;
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &arr)
{
    os << "[";
    if (N > 0)
    {
        os << arr[0];
        for (size_t i = 1; i < N; ++i)
        {
            os << ", " << arr[i];
        }
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::queue<T> &q)
{
    std::queue<T> temp = q;
    os << "queue [";
    if (!temp.empty())
    {
        os << temp.front();
        temp.pop();
        while (!temp.empty())
        {
            os << ", " << temp.front();
            temp.pop();
        }
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::stack<T> &s)
{
    std::stack<T> temp = s;
    os << "stack [";
    if (!temp.empty())
    {
        os << temp.top();
        temp.pop();
        while (!temp.empty())
        {
            os << ", " << temp.top();
            temp.pop();
        }
    }
    os << "]";
    return os;
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::map<K, V> &m)
{
    os << "map {";
    for (const auto &pair : m)
    {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<K, V> &um)
{
    os << "unordered_map {";
    for (const auto &pair : um)
    {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &s)
{
    os << "set [";
    auto it = s.begin();
    if (it != s.end())
    {
        os << *it;
        ++it;
    }
    while (it != s.end())
    {
        os << ", " << *it;
        ++it;
    }
    os << "]";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &us)
{
    os << "unordered_set [";
    auto it = us.begin();
    if (it != us.end())
    {
        os << *it;
        ++it;
    }
    while (it != us.end())
    {
        os << ", " << *it;
        ++it;
    }
    os << "]";
    return os;
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::pair<K, V> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
void pr(std::istream_iterator<std::string> it, T a)
{
    std::cout << *it << " = " << a << std::endl;
}

template <typename T, typename... Args>
void pr(std::istream_iterator<std::string> it, T a, Args... args)
{
    std::cout << *it << " = " << a << std::endl;
    pr(++it, args...);
}

class Solve
{
public:
    vector<vector<int>> subsets;
    vector<int> gcds;

    void dfs(vector<int> l, int progress, vector<int> subset, int gcd = -1)
    {
        if (progress >= l.size())
        {
            if (gcd > 1)
            {
                subsets.push_back(subset);
                gcds.push_back(gcd);
            }
            return;
        }

        if (gcd == -1)
        {
            dfs(l, progress + 1, subset);
            subset.push_back(l[progress]);
            dfs(l, progress + 1, subset, l[progress]);
        }
        else
        {
            dfs(l, progress + 1, subset, gcd);
            subset.push_back(l[progress]);
            dfs(l, progress + 1, subset, __gcd(gcd, l[progress]));
        }
    }

    int calculate(int gcd, vector<int> subset)
    {
        return subset.size() * gcd;
    }

    int solve(vector<int> l)
    {
        dfs(l, 0, vector<int>());
        int somme = 0;
        // print(subsets);
        // print(gcds);
        for (int i = 0; i < subsets.size(); i++)
        {
            // print(calculate(gcds[i], subsets[i]));
            somme += (calculate(gcds[i], subsets[i]) % int(pow(10, 9) + 7) );
        }
        return somme % int(pow(10, 9) + 7);
    }
};

int main()
{
    int n;
    int a;
    vector<int> l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        l.push_back(a);
    }
    // print(l);
    // vector<int> l = {3, 3, 1};
    Solve s = Solve();
    cout << s.solve(l);
    return 0;
}