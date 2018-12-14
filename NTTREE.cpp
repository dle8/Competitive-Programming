#include <bits/stdc++.h>
#include <string.h>
#define maxn 10000+10
using namespace std;

struct node {
	long long v, c, next;
};

node edge[2*maxn];//nen de do thi co 1 duong thoi vi day la cay
int n;
long long totalWeight;
long long weight[maxn];//weight cac duong noi tu 1 nut trong cay con den goc cua cay con do
bool check[maxn];
int head[maxn], socon[maxn];

void dfs1(int u) {
	int i = head[u];
	int v;
	check[u] = false;
	while (i!=0) {
		v = edge[i].v;
		if (check[v]) {
			dfs1(v);
			socon[u]++;
			weight[u]+=(weight[v]+edge[i].c*socon[v]);
		}
		i = edge[i].next;
	}
}

void dfs2(int u) {
	int v, index;
	int i = head[u];
	long long b[maxn];
	int con[maxn];
	index = 0;
	check[u] = false;
	while (i!=0) {
		v = edge[i].v;
		if (check[v]) {
			dfs2(v);
			index++;
			b[index] = weight[v]+edge[i].c*socon[v];
			con[index] = socon[v];
		}
		i = edge[i].next;
	}
	
	for (i=1; i<=index; i++) totalWeight+=b[i]*(socon[u]-con[i]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, w;
	cin >> n;
	for (int i=1; i<=(n-1); i++) {
		cin >> u >> v >> w;
		u++;
		v++;
		edge[2*i].v = v;
		edge[i*2].c = w;
		edge[2*i].next = head[u];
		head[u] = 2*i;
		
		edge[2*i+1].v = u;
		edge[2*i+1].c = w;
		edge[2*i+1].next = head[v];
		head[v] = 2*i+1;
		
	}
	totalWeight=0;
	for (int i=1; i<=n; i++) socon[i] = 1;
	memset(weight, 0, sizeof(weight));
	memset(check, true, sizeof(check));
	dfs1(1);
	memset(check, true, sizeof(check));
	dfs2(1);
	cout << totalWeight << endl;
	return 0;
}
