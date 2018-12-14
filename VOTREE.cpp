#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

struct edge {
	int v, next;
};

int n;
int height[70000+10];
int tnext[70000+10][20];
int it[280000];
edge road[2*70000+10];
bool check[70000+10];
int parent[70000+10];
int head[70000+10];

int lca(int u, int v) {
	int temp;
	if (height[u] < height[v]) {
		temp = u;
		u = v;
		v = temp;
	}
	
	for (int i = int(log(height[u]-height[v])/log(2)); i>=0; i--) {
		if (height[tnext[u][i]]>=height[v]) u = tnext[u][i];
	}
	
	if (u == v) return u;
	
	for (int i = int(log(height[u]-1)/log(2)); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {//while thg cha thu 2^i cua u va thg cha thu 2^i cua v khac nhau
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	return parent[u];//or tnext[u][0]
}

void update(int cs, int u, int v, int i) {//update thg nao la lca cua no
	if (u==i && v==i) {
		it[cs] = i;
	}
	else {
		if (i<=(u+v)/2) {
			update(2*cs, u, (u+v)/2, i);
			if (it[cs] == 0) it[cs] = it[2*cs];
			else it[cs] = lca(it[cs], it[2*cs]);
		}
		
		if (i>=(u+v)/2+1) {
			update(2*cs+1, (u+v)/2+1, v, i);
			if (it[cs] == 0) it[cs] = it[2*cs+1];
			else it[cs] = lca(it[cs], it[2*cs+1]);
		}
	}
}

int findArrLCA(int cs, int u, int v, int x, int y) {//tim lca cua tat ca cac dinh tu u, u+1, ..., v
	if (u==x && v==y) return it[cs];
	else {
		if (x>=(u+v)/2+1) {
			return findArrLCA(2*cs+1, (u+v)/2+1, v, x, y);
		}
		if (y<=(u+v)/2) {
			return findArrLCA(2*cs, u, (u+v)/2, x, y);
		}
		else {
			int left = findArrLCA(2*cs, u, (u+v)/2, x, (u+v)/2);
			int right = findArrLCA(2*cs+1, (u+v)/2+1, v, (u+v)/2+1, y);
			return lca(left, right);
		}
	}
}

void dfs(int u) {
	int v;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = road[i].v;
		if (check[v]) {
			height[v] = height[u] + 1;
			parent[v] = u;
			dfs(v);
		}
		i = road[i].next;
	}
}

void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];
	
	for (int i=1; i<=int(log(n)/log(2)); i++) {
		for (int u=1; u<=n; u++) {
			if (tnext[tnext[u][i-1]][i-1]!=0) //tuc la chua vuot qua goc 
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];
		}
	}
}

void print() {
	for (int i=0; i<100; i++) 
		cout << it[i] << " ";
}

int main() {
	int q;
	int u, v;
	cin >> n >> q;
	memset(check, true, sizeof(check));
	for (int i=1; i<=n-1; i++) {
		cin >> u >> v;
		road[2*i-1].v = v;
		road[2*i-1].next = head[u];
		head[u] = 2*i-1;
		
		road[2*i].v = u;
		road[2*i].next = head[v];
		head[v] = 2*i;
	}
	
	height[1] = 1;
	dfs(1);
	init();
	
	for (int i=1; i<=n; i++) update(1, 1, n, i);
//	print();
		
	for (int i=1; i<=q; i++) {
		cin >> u >> v;
		cout << findArrLCA(1, 1, n, u, v) << endl;
	}
	return 0;
}
