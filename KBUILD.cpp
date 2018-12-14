#include <bits/stdc++.h>
#define maxn 200000+10
#define maxc 1000000000
using namespace std;

struct node {
	long v, next, u;
};

long n;
node graph[2*maxn], cau[maxn];
long height[maxn], tnext[maxn][20], parent[maxn], head[maxn], maxlca[maxn], check[maxn], longestlca[maxn];

long min(long a, long b) {
	if (height[a]<=height[b]) return a;
	else return b;
}

long lca(long u, long v) {
	long temp;
	if (height[v]>height[u]) {
		temp = v;
		v = u;
		u = temp;
	}
	for (int i=int(log(height[u]-height[v])/log(2)); i>=0; i--) 
		if (height[tnext[u][i]]>=height[v] && tnext[u][i]!=0) u = tnext[u][i];
	
	if (u==v) return u;
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) 
		if (tnext[u][i]!=tnext[v][i]) {
			u = tnext[u][i];
			v = tnext[v][i];
		}
		
	return parent[u];
}

void dfs(long u) {
	long v;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==0) {
			check[v] = u;
			height[v] = height[u]+1;
			parent[v] = u;
			dfs(v);	
		}
		i = graph[i].next;
	}
}

void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];
	
	for (int i=1; i<=(log(n)/log(2)); i++)
	for (int u=1; u<=n; u++) 
		if (tnext[tnext[u][i-1]][i-1]!=0) tnext[u][i] = tnext[tnext[u][i-1]][i-1];
}

void dfs2(long u) {//tim nhung thang lca xa nhat ma nhung thang con goc u co the den duoc
	long v, temp;
	long i = head[u];
	temp = maxlca[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==u) {//neu v la con cua u
			dfs2(v);
			temp = min(temp, longestlca[v]);
		}
		i = graph[i].next;
	}
	longestlca[u] = temp;
}

int main() {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	long u, v, ancestor, m, res, temp;
	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> u >> v;
		cau[i].u = u;
		cau[i].v = v;
		
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1; 
	}
	height[0] = maxc;
	height[1] = 1;
	check[1] = -1;
	dfs(1);
	init();
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		ancestor = lca(u, v);
		maxlca[u] = min(maxlca[u], ancestor);
		maxlca[v] = min(maxlca[v], ancestor);
	}
	
	dfs2(1);
	
	res = 0;
	for (int i=1; i<n; i++) {
		if (height[cau[i].u]>height[cau[i].v]) {
			temp = cau[i].u;
			cau[i].u = cau[i].v;
			cau[i].v = temp;
		}
		if (height[longestlca[cau[i].v]]>height[cau[i].u]) res++;
	}
	cout << res;
	return 0;
}
