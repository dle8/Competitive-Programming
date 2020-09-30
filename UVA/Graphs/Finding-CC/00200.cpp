#include <bits/stdc++.h>
using namespace std;

void findTopoOrder(char u, vector<char> &topoOrder, vector<bool> &visited, const vector<vector<char>> &adj) {
    visited[u - 'A'] = true;
    for (char v: adj[u - 'A']) {
        if (!visited[v - 'A']) {
            findTopoOrder(v, topoOrder, visited, adj);
        }
    }
    topoOrder.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    vector<string> words;
    string word;
    vector<bool> existed(26, false), visited(26, false);
    vector<vector<char>> adj(26, vector<char>{});
    while (cin >> word) {
        if (word == "#") {
            break;
        }
        for (char c: word) {
            existed[c - 'A'] = true;
        }
        words.push_back(word);
    }
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            int minLength = min(words[i].size(), words[j].size());
            for (int k = 0; k < minLength; ++k) {
                if (words[i][k] != words[j][k]) {
                    adj[words[i][k] - 'A'].push_back(words[j][k]);
                    break;
                }
            }
        }
    }
    vector<char> topoOrder;
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (existed[c - 'A']) {
            if (!visited[c - 'A']) {
                findTopoOrder(c, topoOrder, visited, adj);
            }
        }
    }
    reverse(topoOrder.begin(), topoOrder.end());
    for (char c: topoOrder) {
        cout << c;
    }
    return 0;
}