#include <bits/stdc++.h>
#include <queue>
#define maxn 10000+10
#define maxm 100000+10
using namespace std;

struct node {
	int v, next;
};

int n, s, t;
node tree[maxm];
bool check[maxn];
int trace[maxn], head[maxn];

bool dfs(int u) {
	int v;
	if (u==t) return true;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = tree[i].v;
		if (check[v])
			if (dfs(v)) return true;
		i = tree[i].next;
	}
	return false;
}

void bfs() {
	int v, u;
	queue<int> q;
	q.push(s);
	check[s] = false;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (u==t) break;
		int i = head[u];
		while (i!=0) {
			v = tree[i].v;
			if (check[v]) {
				q.push(v);
				trace[v] = u;
				check[v] = false;
			}
			i = tree[i].next;
		}
	}
}

void process() {
	int k, res, temp;
	memset(check, true, sizeof(check));
	memset(trace, 0, sizeof(trace));
	bfs();
	k = trace[t];
	res = 0;
	while (k!=s) {
		temp = head[k];
		head[k] = 0;
		memset(check, true, sizeof(check));
		if (!dfs(s)) res++;
		head[k] = temp;
		k = trace[k];
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, dem, m;
	cin >> n >> m >> s>> t;
	dem = 0;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		dem++;
		tree[dem].v = v;
		tree[dem].next = head[u];
		head[u] = dem;
	}
	process();
	return 0;
}
