#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimeter) {
    stringstream ss(s);
    string token;
    vector<string> tokens;
    while (getline(ss, token, delimeter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, cases = 0;
    while (true) {
        if (scanf("%d\n", &n) != 1) {
            break;
        }
        unordered_map<string, int> deg;
        unordered_map<string, vector<string>> adj;
        vector<string> alcohols;
        for (int i = 0; i < n; ++i) {
            string alcohol;
            cin >> alcohol;
            alcohols.push_back(alcohol);
        }
        int edges;
        cin >> edges;
        cin.ignore();
        for (int edge = 1; edge <= edges; ++edge) {
            string input;
            getline(cin, input);
            vector<string> tmp = split(input, ' ');
            ++deg[tmp[1]];
            adj[tmp[0]].push_back(tmp[1]);
        }
        priority_queue<string, vector<string>> q;
        for (string alcohol: alcohols) {
            if (deg[alcohol] == 0) {
                q.push(alcohol);
            }
        }
        cout << "Case #" << ++cases << ": Dilbert should drink beverages in this order: ";
        vector<string> res;
        while (!q.empty()) {
            string u = q.top();
            q.pop();
            res.push_back(u);
            for (string v: adj[u]) {
                --deg[v];
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            cout << ((i == res.size() - 1) ? '.' : ' ');
        }
        cout << "\n\n";
//        cin.ignore();
    }
    return 0;
}