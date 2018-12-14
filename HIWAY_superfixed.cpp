#include <bits/stdc++.h>
#define maxn 100+10
#define maxc 1000000000
using namespace std;

int n, s, t, u, v, l, m;
bool check[maxn][maxn], flag;
int res[maxn], c[maxn][maxn], trace[maxn], sl;
int Path[3], count;

int getDirection(bool direction) {
	if (direction) return -1;
	else return 1;
} 

int fbm() {
	bool updating;
	int d[maxn];
	for (int i=1; i<=n; i++) d[i] = maxc;
	d[s] = 0;
	do {
		updating = false;
		for (int u=1; u<=n; u++)
		for (int v=1; v<=n; v++) 
		if (!check[u][v] && d[v]>d[u]+c[u][v]*getDirection(check[v][u])) {
			d[v] = d[u] +c[u][v]*getDirection(check[v][u]);
			//cam sua check o day-> vi van dang toi uu do duong di nho nhat
			trace[v] = u;					
			updating = true;
		}
	} while (updating);
	if (d[t]==maxc) return -1;
	else return d[t];
}

void dfs(int u, int &sl) {
	sl++;
	res[sl] = u;
	if (u==t) {
		flag = true;
		return;
	}
	for (int v=1; v<=n; v++) 
	if (check[u][v] && !flag) {
		check[u][v] = false;
		dfs(v, sl);
		if (flag) return;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (i==j) c[i][j] = 0;
			else c[i][j] = maxc;
		}
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> l;
		c[u][v] = l;
		c[v][u] = l;
	}
	
	for (int i=1; i<=n; i++) memset(check[i], false, sizeof(check[i]));
	
	for (int i=1;i<=2;i++){
		Path[i] = fbm();
		if (Path[i]==-1) {
			cout<<-1;
			return 0;
		}
		v = t;
		while (trace[v]!=0) {
			u = trace[v];
			if (check[v][u]) check[v][u] = false;
			else check[u][v] = true;
			v = u;
		}	
	}

	cout << Path[1] + Path[2] << "\n";
	for (int o=1;o<=2;o++){
		flag = false;
		sl=0;
		dfs(s, sl);
		cout<<sl<<" ";
		for (int i=1; i<=sl; i++) cout << res[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
