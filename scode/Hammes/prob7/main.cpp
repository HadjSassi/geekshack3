#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

int safe_stoi(const string& str) {
    try {
        size_t pos;
        int result = stoi(str, &pos);
        if (pos < str.size()) {
            throw invalid_argument("Invalid argument");
        }
        return result;
    } catch (const invalid_argument& e) {
        cerr << "Error: Invalid argument - " << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (const out_of_range& e) {
        cerr << "Error: Out of range - " << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    string ch;
    getline(cin, ch);

    vector<string> l;
    size_t pos = 0;
    while ((pos = ch.find(" ")) != string::npos) {
        l.push_back(ch.substr(0, pos));
        ch.erase(0, pos + 1);
    }
    l.push_back(ch);

    int n = safe_stoi(l[0]);
    int z = safe_stoi(l[1]);

    vector<vector<int>> li;

    for (int i = 0; i < n; ++i) {
        getline(cin, ch);
        l.clear();
        pos = 0;
        while ((pos = ch.find(" ")) != string::npos) {
            l.push_back(ch.substr(0, pos));
            ch.erase(0, pos + 1);
        }
        l.push_back(ch);

        li.push_back({safe_stoi(l[0]), safe_stoi(l[1])});
    }

    auto sortup = [](const vector<vector<int>>& l) {
        vector<vector<int>> sorted_l = l;
        sort(sorted_l.begin(), sorted_l.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0];
        });
        return sorted_l;
    };

    auto sortbottom = [](const vector<vector<int>>& l) {
        vector<vector<int>> sorted_l = l;
        sort(sorted_l.begin(), sorted_l.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        return sorted_l;
    };

    int m = 0;

    while (z > 1) {
        if (li.size() > 1) {
            if (sortup(li)[0][0] <= sortbottom(li)[0][1] + sortbottom(li)[1][1]) {
                li = sortup(li);
                m += li[0][0];
                li.erase(li.begin());
                z -= 2;
            } else {
                li = sortbottom(li);
                m += li[0][1] + li[1][1];
                li.erase(li.begin());
                li.erase(li.begin());
                z -= 2;
            }
        }
    }

    if (z == 1) {
        if (sortup(li)[0][0] <= sortbottom(li)[0][1]) {
            li = sortup(li);
            m += li[0][0];
            z = 0;
        } else {
            li = sortbottom(li);
            m += li[0][1];
        }
    }

    cout << m << endl;

    return 0;
}
