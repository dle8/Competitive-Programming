#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int n;
int sum;

struct edge {
	int v, c, next;
};

edge grass[2*1000+10];
int head[1000+10];
int parent[1000+10];
int tnext[1000+10][20];
bool tcheck[1000+10];
int dist[1000+10][20];//dist[u][i] la khoang cach tu thang u cho den thang cha thu 2^i cua u
int height[1000+10];

void init() {//khoi tao mang tnext[u][i] (thang cha thu 2^i cua u)
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];	
	
	for (int i=1; i<=(log(n)/log(2)); i++) {
		for (int u=1; u<=n; u++) {
			if (tnext[tnext[u][i-1]][i-1]!=0) {
			//neu nhu tnext[u][i] k phai nut goc
				dist[u][i] = dist[u][i-1] + dist[tnext[u][i-1]][i-1];
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];
			}
		}
	}
}

void dfs(int u) {
	tcheck[u] = false;
	int i = head[u];
	int v;
	while (i!=0) {//chua het con
		v = grass[i].v;
		if (tcheck[v]) {
			parent[v] = u;
			height[v] = height[u] + 1;
			dist[v][0] = grass[i].c;
			dfs(v);
		}
		i = grass[i].next;
	}
}

void lca(int u, int v) {
	int temp;
	if (height[u] < height[v]) {//cho do phai xet 2 truong hop thi hay dam bao u luon la thang co do cao lon hon
		temp = u;
		u = v;
		v = temp;
	}
	
	for (int i=int((log(height[u] - height[v])/log(2))); i>=0; i--) {
		if (height[tnext[u][i]]>=height[v]) {
			sum += dist[u][i];
			u = tnext[u][i];
		}
	}
	
	if (u==v) return;//neu u bang v thi thg u (hoac v) chinh la lca cua u, v ban dau
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {
			sum += dist[u][i];
			sum += dist[v][i];
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	sum= sum + (dist[u][0] + dist[v][0]);
	
	//parent[u] chinh la lca
}

int main() {
	int q;
	int u, v, c;
	memset(tcheck, true, sizeof(tcheck));
	cin >> n >> q;
	for (int i=1; i<=n-1; i++) {
		cin >> u >> v >> c;
		grass[2*i-1].v = v;
		grass[2*i-1].c = c;
		grass[2*i-1].next = head[u];
		head[u] = 2*i-1;
		
		grass[2*i].v = u;
		grass[2*i].c = c;
		grass[2*i].next = head[v];
		head[v] = 2*i;
	}
	
	height[1] = 1;
	dfs(1);
	init();
	
	for (int i=1; i<=q; i++) {
		cin >> u >> v;
		sum = 0;
		lca(u,v);
		cout << sum << "\n";
	}
	return 0;
}
