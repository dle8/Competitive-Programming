#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int cities;
    cin >> cities;
    for (int city = 1; city <= cities; ++city) {
        int n, roads;
        cin >> n >> roads;
        vector<vector<int>> adj(n, vector<int> {});
        for (int road = 1; road <= roads; ++road) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int stronglyConnectedComponent = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++stronglyConnectedComponent;
                dfs(i, adj, visited);
            }
        }
        cout << stronglyConnectedComponent - 1 << '\n';
    }
    return 0;
}