#include <bits/stdc++.h>
#define maxn 10000+10
#define maxc 1000000000
#define debug cout << "debug" << "\n"
using namespace std;

struct node {
	long v, next;
};

node graph[2*maxn];
long n, res, head[maxn], d[maxn][4], sticker[maxn], check[maxn];

void dfs(long u) {
	long v, minv;
	bool isLeaf = true;
	long i = head[u];
	
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==0) {
			isLeaf = false;
			check[v] = u;
			dfs(v);
			d[u][1]+=min(d[v][2], d[v][3]);
			d[u][2]+=min(d[v][1], d[v][3]);
			d[u][3]+=min(d[v][1], d[v][2]);
		}
		i = graph[i].next;
	}
	
	if (isLeaf) for (int c=1; c<=3; c++) d[u][c] = c;
}

void truyvet(long u, long color) {
	long v;
	bool isLeaf = true;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==u) {
			isLeaf = false;
			if (color==1) sticker[v] = (d[v][2]<d[v][3]) ? 2:3;
			if (color==2) sticker[v] = (d[v][1]<d[v][3]) ? 1:3;
			if (color==3) sticker[v] = (d[v][2]<d[v][1]) ? 2:1;
			truyvet(v, sticker[v]);
		}
		i = graph[i].next;
	}
	if (isLeaf) sticker[u] = color;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v;
	cin >> n;
	memset(head, 0, sizeof(head));
	memset(check, 0, sizeof(check));
	for (int i=1; i<n; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1; 
	}
	dfs(1);
	
	res = maxc;
	for (int c=1; c<=3; c++) 
		if (d[1][c]<res) {
			res = d[1][c];
			u = c;
		}
	sticker[1] = u;
	truyvet(1, u);
	cout << res << "\n";
	for (int i=1; i<=n; i++) cout << sticker[i] << "\n";
	return 0;
}
