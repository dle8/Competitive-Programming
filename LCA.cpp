#include <bits/stdc++.h>
#include <math.h>
#define maxn 1000+10
using namespace std;

struct node {
	int v, next;
};

int n;
node graph[maxn];
bool check[maxn];
int parent[maxn], tnext[maxn][10], height[maxn], head[maxn];

void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];

	for (int i=1; i<=int(log(n)/log(2)); i++)
		for (int u=1; u<=n; u++){
			if (tnext[tnext[u][i-1]][i-1]!=0)
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];
		}	
}

void dfs(int u) {
	int v;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			height[v] = height[u]+1;
			parent[v] = u;
			dfs(v);
		}
		i = graph[i].next;
	}
}

int lca(int u, int v) {
	int temp;
	if (height[u]<height[v]) {
		temp = u;
		u = v;
		v = temp;
	}
	
	for (int i=int(log(height[u]-height[v])/log(2)); i>=0; i--) {
		if (height[tnext[u][i]]>=height[v])
			u = tnext[u][i];
	}
	
	if (u==v) return u;
	
	for (int i=log(height[u]-1)/log(2); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	return parent[u];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test, m, dem, q, v, u;
	cin >> test;
	for (int i=1; i<=test; i++) {
		cin >> n;
		dem = 0;
		memset(head, 0, sizeof(head));
		memset(check, true, sizeof(check));
		memset(height, 0, sizeof(height));
		for (int j=1; j<=n; j++) {
			cin >> m;
			for (int child=1; child<=m; child++){
				cin >> v;
				dem++;
				graph[dem].v = v;
				graph[dem].next = head[j];
				head[j] = dem;
			}
		}	
		cout << "Case " << i << ":" << "\n";
		height[1] = 1;
		dfs(1);
		init();
		cin >> q;
		for (int k=1; k<=q; k++) {
			cin >> u >> v;
			cout << lca(u, v) << "\n";
		}
	}
	return 0;
}
