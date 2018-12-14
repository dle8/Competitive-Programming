#include <bits/stdc++.h>
#define maxn 10000+10
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, m, root;
	while (getline(cin, n)) {
		memset(head, 0, sizeof(head));
		for (int i=1; i<=(n-1); i++) {
			cin >> u >> v;
			graph[2*i].v = v;
			graph[2*i].next = head[u];
			head[u] = 2*i;
			
			graph[2*i+1].v = u;
			graph[2*i+1].next = head[v];
			head[v] = 2*i+1;
		}		
		cin >> m;
		for (int i=1; i<=m; i++) {
			cin >> tcase;
			switch(tcase) {
				case '!':
					cin >> root;
					break;
				case '?':
					cin >> u >> v;
					cout << lca(u, v) << endl;
					break;
			}
		}
		cin >> endTest;
	}
	return 0;
}
