#include <iostream>
#include <math.h>
#include <string.h>
#define EPS 1e-9
 
using namespace std;
 
struct Tedge{
	int v, c, next;
};
 
Tedge memory[200000+10];
int head[100000+10];
bool check[100000+10];
int parent[100000+10];
int tnext[100000+10][18];//log 100000
int height[100000+10];
int tmax[100000][20], tmin[100000][20];
int rmax;
int rmin;
 
int n;
int k;
 
int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}
 
int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}
 
void lca(int u, int v) {
	int temp;
	
	if (height[u]< height[v]) {
		temp = u;
		u = v;
		v = temp;
	}
	for (int i=int(log(height[u]-height[v])/log(2)); i>=0; i--)
	if (height[tnext[u][i]]>=height[v]) {
		rmax = max(rmax, tmax[u][i]);
		rmin = min(rmin, tmin[u][i]);
		u=tnext[u][i];
	}
		
	if (u==v) return;
	//return u;	
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) 
	if (tnext[u][i]!=tnext[v][i]) {//moi so x dc bieu thi duoi he nhi phan
		rmax = max(rmax, tmax[u][i]);
		rmin = min(rmin, tmin[u][i]);
		u = tnext[u][i];
		rmax = max(rmax, tmax[v][i]);
		rmin = min(rmin, tmin[v][i]);
		v = tnext[v][i];
	}
 
	rmax = max(rmax, max(tmax[v][0], tmax[u][0]));
	rmin = min(rmin, min(tmin[v][0], tmin[u][0]));
//	return parent[u];
}
 
void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];
	
	for (int i=1; i<=(log(n)/log(2)); i++) {
		for (int u=1;u<=n;u++)
		if (tnext[tnext[u][i-1]][i-1]!=0) {//k vuot qua nut goc
			tmax[u][i] = max(tmax[u][i-1], tmax[tnext[u][i-1]][i-1]);
			tmin[u][i] = min(tmin[u][i-1], tmin[tnext[u][i-1]][i-1]);
			tnext[u][i] = tnext[tnext[u][i-1]][i-1];
		}
	}
}
 
void dfs(int u) {
	int i = head[u];
	int v;
	check[u] = false;
	while (i!=0) {//duyet danh sach adjacency list/ linked list canh ke cua u
		v = memory[i].v;
		if (check[v]) {
			parent[v] = u;
			height[v] = height[u] + 1;
			tmax[v][0] = memory[i].c;
			tmin[v][0] = memory[i].c;
			dfs(v);
		}
		i = memory[i].next;
	}
}
 
int main() {
	int u, v, c;
	cin >> n;
	memset(check, true, sizeof(check));
	for (int i=1; i<= n-1; i++) {
		cin >> u >> v >> c;
		memory[2*i-1].v = v;
		memory[2*i-1].c = c;
		memory[2*i-1].next = head[u];
		head[u] = 2*i-1;
		
		memory[2*i].v = u;
		memory[2*i].c = c;
		memory[2*i].next = head[v];
		head[v] = 2*i;
	}
	
	height[1] = 1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=(log(n)/log(2));j++) tmin[i][j]= 1000000000+100;//neu k khoi tao tmin thi mac dinh tmin = 0; luc day se lay tmin = 0 
	dfs(1);
	init();
	
	cin >> k;
	for (int i=1; i<=k; i++) {
		cin >> u >> v;
		rmin = 1000000000+100;
		rmax = -1;
		lca(u, v);
		cout << rmin <<  " " << rmax << endl;
	}
	return 0;
} 
