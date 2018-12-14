#include <bits/stdc++.h>
#define maxn 200+10
#define oo 1e9
using namespace std;

struct node {
	long v;
	node* next;
};

long n;

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void read() {
	cin >> n;
	node* p;
	FOR(i, 1, n)
	FOR(j, 1, n) {
		cin >> c[i][j];
		if (j<=i) c[i][j] = oo;
		if (j==1) c[i][n+1] = c[i][j];
	}
	
	c[1][n+1] = oo;
}

void createGraph() {
	FOR(i, 1, n-1)
	FOR(j, i+1, n) d[i][j] = oo;
	FOR(i, 2, n) d[i][n+1] = 1;
}

int getDirection(long flow) {
	if (flow>=0) return 1;//tai sao 
	else return -1;
}

bool findPath() {
	long v;
	bool updating;
	FOR(i, 1, n) dist[i] = oo;
	d[1] = 0;
	do {
		updating = false;
		FOR(u, 1, n) {
			FOR(v, u+1, n+1) {
				if (d[u][v]-f[u][v]>0 && dist[v]>dist[u]+c[u][v]*getDirection(f[u][v])) {
					trace[v] = u;
					dist[v] = dist[u]+c[u][v]*getDirection(f[u][v]);
					updating = true;
				}
			}
		}
		
	} while (updating);
	if (dist[n+1]==oo) return false;
	return true;
}

void updateFlow(long flow) {
	long v = t;
	while (v!=s) {
		long u = trace[v];
		f[u][v]+=flow;
		f[v][u]-=flow;
		v = u;
	}
}

void process() {
	bool found;
	long flow;
	FOR(i, 1, n) memset(f[i], 0, sizeof(f[i]));
	createGraph();	
	while (true) {
		found = findPath();
		if (!found) break;
		updateFlow(1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	read();
	process();
	print();
	return 0;
}
