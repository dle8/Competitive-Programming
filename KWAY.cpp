#include <iostream>
#include <string.h>
#define maxc 1000000000
#define maxn 100+10
using namespace std;

long n, m, k, s, f, slTram, result[maxn], d[maxn], trace[maxn], c[maxn][maxn], path[maxn];
bool flag, check[maxn][maxn];

long getDirection(bool direction) {
	if (direction) return -1;
	else return 1;
}

long fbm() {
	bool updating;
	for (int i=1; i<=n; i++) d[i] = maxc;
	d[s] = 0;
	do {
		updating = false;
		for (int u=1; u<=n; u++)
		for (int v=1; v<=n; v++) {
			if (!check[u][v]/*neu chua di chieu (u,v)*/ && d[v]>d[u]+c[u][v]*getDirection(check[v][u])/*neu check(v, u) tuc la cung (u,v) di nguoc-> lay gia tri am cua c(u,v)*/) {
				d[v] = d[u]+c[u][v]*getDirection(check[v][u]);
				trace[v] = u;
				updating = true;				
			}
		}
	} while(updating);
	if (d[f]==maxc) return -1;
	else return d[f];
}

void dfs(long u, long& slTram) {
	slTram++;
	result[slTram] = u;
	if (u==f) {
		flag = true;
		return;
	}
	for (int v=1; v<=n; v++) {
		if (check[u][v]) {//neu co di qua chieu (u,v)
			check[u][v] = false;//bo luon chieu (u,v) de cac lan trace sau khong di vao day nua
			dfs(v, slTram);
		}
		if (flag) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long cost, totalPath, u, v;
	cin >> n >> m >> k >> s >> f;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++) {
		if (i==j) c[i][j] = 0;
		else c[i][j] = maxc;
	}
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> cost;
		c[u][v] = cost;
		c[v][u] = cost;
	}
	
	for (int i=1; i<=n; i++) memset(check[i], false, sizeof(check[i]));
	totalPath = 0;
	for (int i=1; i<=k; i++) {
		path[i] =  fbm();
		if (path[i]==-1) {
			cout << -1;
			return 0;
		}
		totalPath+=path[i];
		v = f;
		while (trace[v]!=0) {
			u = trace[v];
			if (check[v][u]) check[v][u] = false;
			else check[u][v] = true;
			v= u;
		}
	}
	cout << totalPath << "\n";
	for (int i=1; i<=k; i++) {
		slTram = 0;
		flag = false;
		dfs(s, slTram);
		cout << slTram << " ";
		for (int j=1; j<=slTram; j++) cout << result[j] << " ";
		cout << "\n";
	}
	return 0;
}
