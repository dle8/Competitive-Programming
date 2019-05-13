#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define sz(x) int(x.size())

using namespace std;

#define maxn 10000 + 10

class Solution {

public:
		vector<vector<int>> adj;
		bool check[maxn + 10];

		Solution(): adj(maxn + 10) {};

		void dfs(int u, vector<int> &res) {
			check[u] = true;
			vector<int> usedColor;
			FOR(i, 0, sz(adj[u]) - 1) {
				int v = adj[u][i];
				if (res[v - 1] != 0) usedColor.pb(res[v - 1]);
			}
			if (sz(usedColor) == 0) res[u - 1] = 1;
			else {
				FOR(i, 1, 4) {
					bool flag = false;
					FOR(j, 0, sz(usedColor) - 1) {
						if (usedColor[j] == i) {
							flag = true;
							break;
						}
					}
					if (!flag) {
						res[u - 1] = i;
						break;
					}
				}
			}
			FOR(i, 0, sz(adj[u]) - 1) {
				if (!check[adj[u][i]]) dfs(adj[u][i], res);
			}
		}

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
			adj.clear();
			FOR(i, 0, sz(paths) - 1) {
				adj[paths[i][0]].pb(paths[i][1]);
				adj[paths[i][1]].pb(paths[i][0]);
			}
			memset(check, false, sizeof(check));
			vector<int> res(n);
			FOR(i, 1, n) if (!check[i]) dfs(i, res);
			return res;
    }
};
