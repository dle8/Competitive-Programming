#include <bits/stdc++.h>
#include <queue>
#define maxn 1000+10
#define maxm 1500+10
using namespace std;

struct node {
	int v, next;
};

node tree[2*maxm];
int n, m;
bool check[maxn], side[maxn][maxn];
int kTrace[maxn], dTrace[maxn], bTrace[maxn], lab[maxn], head[maxn];

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (r1<r2) lab[r2] = r1;//dam bao cho thang nho hon luon lam cha -> 1 la nut goc
	else lab[r1] = r2;
}

void dfs(int u) {
	int v;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = tree[i].v;
		if (check[v]) {
			dTrace[u] = v;
			dfs(v);
		}
		i = tree[i].next;
	}
}

void bfs() {
	int u, v;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		check[u] = false;
		
		int i = head[u];
		while (i!=0) {
			v = tree[i].v;
			if (check[v]) {
				check[v] = false;
				bTrace[v] = u;
				q.push(v);
			}
			i = tree[i].next;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int r1, r2, root, u, v;
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		memset(side[i], false, sizeof(side[i]));
	for (int i=1; i<=n; i++) lab[i] = -1;
	memset(kTrace, 0, sizeof(kTrace));
	//cach tim cay khung dau tien: kruskal. cho nut 1 lam goc bang cach cho r1<r2
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		side[u][v] = true;
		r1 = getRoot(u);
		r2 = getRoot(v);
		if (r1!=r2) {
			disjointSet(r1, r2);
			kTrace[u] = v;			
		}
		
		tree[2*i].v = v;
		tree[2*i].next = head[u];
		head[u] = 2*i;
		
		tree[2*i+1].v = u;
		tree[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	
	memset(check, true, sizeof(check));
	memset(dTrace, 0, sizeof(dTrace));
	dfs(1);
	memset(check, true, sizeof(check));
	memset(bTrace, 0, sizeof(bTrace));
	bfs();
	cout << 3 << endl;
	//in ra cay khung tim bang kruskal
	root = 1;
	while (kTrace[root]!=0) {
		if (side[root][kTrace[root]]) cout << root << " " << kTrace[root] << endl;
		else cout << kTrace[root] << " " << root << endl;
		root = kTrace[root];
	}
	//in ra cay khung tim bang dfs
	root = 1;
	while (dTrace[root]!=0) {
		if (side[root][dTrace[root]]) cout << root << " " << dTrace[root] << endl;
		else cout << dTrace[root] << " " << root << endl;
		root = dTrace[root];
	}
	//in ra cay khung tim bang bfs
	for (int i=1; i<=n; i++) {
		if (bTrace[i]!=0) {
			if (side[i][bTrace[i]]) cout << i << " " << bTrace[i] << endl;
			else cout << bTrace[i] << " "<< i<< endl;	
		}
	}
	return 0;
}
