#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#define maxn 30000+10
#define maxq 300000+10
using namespace std;

struct node {
	string tcase;
	string ans;
	int u, v;
};

struct node2 {
	int v, next;
};

node2 graph[3*maxq];
node query[maxq];
bool check[maxn];
int n;
int si[maxn], ei[maxn], pen[maxn], head[maxn], lab[maxn], height[maxn], parent[maxn], it[8*maxn], tnext[maxn][20];

void dfs(int u, int& dem) {
	int v;
	int i = head[u];
	dem++;
	si[u] = dem;
	check[u] = false;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			height[v] = height[u]+1;
			parent[v] = u;
			dfs(v, dem);	
		}
		i = graph[i].next;
	}
	dem++;
	ei[u] = dem;
}

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

void update(int cs, int u, int v, int i, int val) {
	if (u==i && v==i) {
		it[cs] = val;
		return;
	}
	int mid = (u+v)/2;
	if (i<=mid) {
		it[cs]-=it[2*cs];
		update(2*cs, u, mid, i, val);
		it[cs]+=it[2*cs];
	}
	else {
		it[cs]-=it[2*cs+1];
		update(2*cs+1, mid+1, v, i, val);
		it[cs]+=it[2*cs+1];
	}
}

int getPenguins(int cs, int u, int v, int l, int r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	int mid = (u+v)/2;
	return (getPenguins(2*cs, u, mid, l, r)+getPenguins(2*cs+1, mid+1, v, l, r));
}

void init() {//cho lca
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];//parent 0 nhung thang root la 0
	
	for (int i=1; i<=int(log(n)/log(2)); i++) {
		for (int u=1; u<=n; u++) {
			if (tnext[tnext[u][i-1]][i-1]!=0) 
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];
		}
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
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {//while thang cha thu 2^i cua u va thang cha thu 2^i cua v con khac nhau
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	return parent[u];//or tnext[u][0]
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, r1, r2, dem, u, v, toU, toV, toLCA, ancestor;
	string tcase;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> pen[i];
		lab[i] = -1;	
	}
	pen[0] = 0;
	dem = 0;
	cin >> q;
	for (int i=1; i<=q; i++) {
		cin >> tcase >> u >> v;
		query[i].tcase = tcase;
		query[i].u = u;
		query[i].v = v;
		if (tcase == "bridge") {
			r1 = getRoot(u);
			r2 = getRoot(v);
			if (r1!=r2) {
				disjointSet(r1, r2);
				query[i].ans = "yes";
				
				dem++;
				graph[dem].v = v;
				graph[dem].next = head[u];
				head[u] = dem;
				
				dem++;
				graph[dem].v = u;
				graph[dem].next = head[v];
				head[v] = dem;
				
			} else query[i].ans = "no";
		}
		if (tcase == "excursion") {
			r1 = getRoot(u);
			r2 = getRoot(v);
			if (r1!=r2) query[i].ans = "impossible";
		}
	}
	
	memset(check, true, sizeof(check));
	for (int i=1; i<=n; i++) {
		r1 = getRoot(i);
		if (check[r1]) {
			check[r1] = false;
			dem++;
			graph[dem].v = r1;
			graph[dem].next = head[0];
			head[0] = dem;
		}
	}
	
	memset(check, true, sizeof(check));
	height[0] = 0;
	dem = -1;
	dfs(0, dem);
	for (int i=1; i<=n; i++) {
		//update theo kieu cu
		update(1, 1, 2*n, si[i], pen[i]);
		update(1, 1, 2*n, ei[i], -pen[i]);
	}
	
	init();
	
	for (int i=1; i<=q; i++) {
		if (query[i].tcase=="bridge") cout << query[i].ans << "\n";
		else if (query[i].tcase=="penguins") {
			update(1, 1, 2*n, si[query[i].u], query[i].v);
			update(1, 1, 2*n, ei[query[i].u], -query[i].v);
			pen[query[i].u] = query[i].v;
		}
		else {
			if (query[i].ans=="impossible") cout << query[i].ans << "\n";
			else {
				ancestor = lca(query[i].u, query[i].v);
				toU = getPenguins(1, 1, 2*n, 1, si[query[i].u]);
				toV = getPenguins(1, 1, 2*n, 1, si[query[i].v]);
				toLCA = getPenguins(1, 1, 2*n, 1, si[ancestor]);
				cout << toU+toV-2*toLCA+pen[ancestor] << "\n";
			}
		}
	}
	return 0;
}
