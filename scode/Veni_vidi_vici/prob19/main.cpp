

#include <bits/stdc++.h>
using namespace std;

const int n = 14;
string cards[14];
bool seen[16385][200];
vector<int> submasks[16385];
int mask_value[16385];
int max_score, acc;

int solve(vector<string> cards, bool straight) {
    if (straight) {
        int sum = 0;
        sort(cards.begin(), cards.end());
        for (string c : cards) {
            if (c[1] == 'A') {
                if (cards[0][1] == '2') sum += 1;
                else sum += 10;
            }
            else if (c[1] == 'J') sum += 10;
            else if (c[1] == 'Q') sum += 10;
            else if (c[1] == 'K') sum += 10;
            else sum += stoi(c.substr(1));
        }
        return sum;
    } else {
        int val;
        if (cards[0][1] == 'J') val = 10;
        else if (cards[0][1] == 'Q') val = 10;
        else if (cards[0][1] == 'K') val = 10;
        else if (cards[0][1] == 'A') val = 10;
        else val = stoi(cards[0].substr(1));
        return val * cards.size();
    }
}

bool straight(const vector<string>& cards) {
    vector<int> mp(26);
    for (const string& card : cards) {
        mp[card[0] - 'A']++;
        if (mp[card[0] - 'A'] >= 3)
            return true;
    }
    return false;
}

bool same_value_different_suits(const vector<string>& cards) {
    if ((int) cards.size() != 3 && (int) cards.size() != 4)
        return false;
    for (int i = 1; i < int(cards.size()); i++)
        if (cards[i].substr(1) != cards[i - 1].substr(1))
            return false;
    for (int i = 1; i < int(cards.size()); i++)
        if (cards[i][0] == cards[i - 1][0])
            return false;
    return true;
}

void brute(int cur_mask) {
    max_score = max(max_score, acc);
    if (seen[cur_mask][acc])
        return;
    seen[cur_mask][acc] = true;
    for (int i : submasks[cur_mask]) {
        if (mask_value[i] != -1) {
            acc += mask_value[i];
            brute((cur_mask | i));
            acc -= mask_value[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(mask_value, -1, sizeof mask_value);

    max_score = 0;
    acc = 0;

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    for (int i = 0; i < (1 << n); i++)
        for (int j = 1; j < (1 << n); j++)
            if (((i & j) == 0))
                submasks[i].emplace_back(j);

    for (int i = 0; i < (1 << n); i++) {
        vector<string> cur_cards;
        for (int j = 0; j < n; j++)
            if ((i & (1 << j)))
                cur_cards.emplace_back(cards[j]);
        if (straight(cur_cards)) {
            mask_value[i] = solve(cur_cards, true);
        } else if (same_value_different_suits(cur_cards)) {
            mask_value[i] = solve(cur_cards, false);
        }
    }

    brute(0);

    if (max_score > 72)
        cout << "YES " << max_score << '\n';
    else
        cout << "NO\n";

    return 0;
}



