#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct road {
	int v, next;
	bool have2;
};


int n;
bool contains2;
bool check[10000+10];
road canh[2*10000+10];
bool live[10000+10][20];//live[u][i] la co hay khong 1 duong co ki hieu = 2 trong khoang tu u den thang cha thu 2^i cua u
int tnext[10000+10][20];//tnext[u][i] la thg cha thu 2^i cua u 
int parent[10000+10];
int height[10000+10];
int head[10000+10];

void dfs(int u) {
	int v;
	int i = head[u];
	check[u] = false; //check la thang u da dc visited
	while (i!=0) {//kiem tra xem da visit cac thang lien ke u chua. neu i=0 tuc la dang o thang con cuoi cung vi chi so next cua thg con cuoi k dc khoi tao
		v = canh[i].v;
		if (check[v]) {
			height[v] = height[u] + 1;
			live[v][0] = canh[i].have2;
//			cout << live[v][0] << " " << u << " " << v << "\n";
			parent[v] = u;
			dfs(v);	
		}		
		i = canh[i].next;
	}	
}

void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];
	
	for (int i=1; i<=int(log(n)/log(2)); i++)
		for (int u=1; u<=n; u++) {
			if (tnext[tnext[u][i-1]][i-1]!=0) {
				live[u][i] = live[u][i-1] || live[tnext[u][i-1]][i-1];
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];
			}
		}
}

void lca(int u, int v) {
	int temp;
	if (height[u] < height[v]) {
		temp = u;
		u = v;
		v = temp;
	}
	
	for (int i=int(log(height[u]-height[v])/log(2)); i>=0; i--) {
		if (height[tnext[u][i]] >= height[v]) {
			contains2 = contains2 || live[u][i];
			u = tnext[u][i];
		}
	}
	
	if (u==v) return;
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {
			contains2 = contains2 || live[u][i];
			contains2 = contains2 || live[v][i];
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	contains2 = contains2 || live[u][0];
	contains2 = contains2 || live[v][0];
}

int main() {
	int m;
	int u, v, k;
	string ans;
	memset(check, true, sizeof(check));
	cin >> n >> m;
	for (int i=1; i<=n-1; i++){//u = i+1;
		cin >> v >> k;
		contains2 = false;
		if (k==2) contains2 = true;		
		canh[2*i-1].v = v;
		canh[2*i-1].have2 = contains2;
		canh[2*i-1].next = head[i+1];
		head[i+1] = 2*i-1;
		
		canh[2*i].v = i+1;
		canh[2*i].have2 = contains2;
		canh[2*i].next = head[v];
		head[v] = 2*i;
		
	}
	
	height[1] = 1;
	dfs(1);
	init();
	
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		contains2 = false;
		lca(u,v);
		if (contains2) ans = "YES";
		else ans = "NO";
		cout << ans << endl;
	}
	return 0;
}
