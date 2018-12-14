#include <iostream>
#include <string.h>
#define maxn 15000+100
using namespace std;
int n, m;

struct edge {
	int v, c, next;
};

edge roads[2*maxn];
bool check[maxn];
int head[maxn], d[maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void prim() {
	int minVal, dinh, nodeInTree, j, v;
	long weight;
	for (int i=1; i<=n; i++) d[i] = 1000000000;
	d[1] = 0;
	weight = 0;
	memset(check, true, sizeof(check));
	while (true) {
		minVal = 1000000000;
		for (int i=1; i<=n; i++) //tim dinh gan cay khung nhat
			if (check[i] && (minVal>d[i])) {//xet nhung thang nao chua co trong cay khung va d[i] tuong ung
				minVal = d[i];
				dinh = i;
			}
		
		weight+=minVal;
		nodeInTree++;
		if (nodeInTree == n) break; 
		check[dinh] = false;
		
		j = head[dinh];
		while (j!=0) {//duyet nhung thang co duong di tu 'dinh' va update mang d
			v = roads[j].v;
			if (check[v]) d[v] = min(d[v], roads[j].c);
			j = roads[j].next;
		}
	}
	
	cout << weight;
}

int main() {
	int u, v, c;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> c;
		roads[2*i].v = v;
		roads[i*2].c = c;
		roads[2*i].next = head[u];
		head[u] = 2*i;
		
		roads[2*i+1].v = u;
		roads[2*i+1].c = c;
		roads[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	prim();
	return 0;
}
