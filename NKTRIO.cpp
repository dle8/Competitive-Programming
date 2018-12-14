#include <bits/stdc++.h>
#define maxm 500000+10
#define maxn 1000+10
using namespace std;

struct node {
	int v, next;
};

node graph[maxm];
int n;
bool flag;
int a[maxn][maxn], trace[maxn], head[maxn];
bool open[maxn];
int check[maxn];

void findCycle(int u, int v) {
	int temp = u;
	while (trace[temp]!=v) {
		if (a[v][trace[temp]]==1) {
			cout << v << " " << trace[temp] << " " << temp;
			flag = true;
			break;
		}
		else temp = trace[temp];
	}
}

void dfs(int u) {
	int v;
	if (flag) return;
	open[u] = true;
	int i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (flag) return;
		if (open[v]) findCycle(u, v);
		if (check[v]==0 || check[v]==u) {
			if (check[v]==0) check[v] = u;
			trace[v] = u;
			dfs(v);
		}
		i = graph[i].next;
	}
	open[u] = false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("nktrio.inp", "r", stdin);
//	freopen("nktrio.out", "w", stdout);
	int dem = 0;
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
			if (a[i][j]==1) {
				dem++;
				graph[dem].v = j;
				graph[dem].next = head[i];
				head[i] = dem;
			}
		}
	
	flag = false;
	memset(open, false, sizeof(open));
	memset(check, 0, sizeof(check));
	for (int i=1; i<=n; i++) {
		if (flag) break;
		dfs(i);
	}
	if (!flag) cout << -1 << " " << -1 << " " << -1;
	return 0;
}
