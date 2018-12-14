#include <iostream>
#include <math.h>
#include <stack>
#include <list>
using namespace std;

int d[100];
bool visited[100];
int trace[100];
int dist[100][100];

int n, m, k;

void init() {
	for (int i=0; i<n; i++) {
		visited[i] = false;
		d[i] = 1000000000;
		trace[i] = -1;
	}
}

void update(int u, int v) {
	if (d[v] > d[u] + dist[u][v]) {
		d[v] = d[u] + dist[u][v];
		trace[v] = u;
	}
}

void dijkstra(int u, int v) {
	int x = u;
	int y = v;
	
	d[x] = 0;
	
	while (x != y) {
		visited[x] = true;
		for (int i=0; i<n; i++) {
			if ((!visited[i]) && (dist[x][i] != 1000000000)) {
				update(x, i);
			}
		}
		
		int min = 1000000000;
		for (int i=0; i<n; i++) {
			if ((d[i] < min) && (!visited[i])) {
				min = d[i];
				x = i;
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) dist[i][j] = 0;
			else dist[i][j] = 1000000000;
		}
	}	
	
	for (int i=0; i<m; i++) {
		int u, v, c;
		cin>> u >> v >> c;
		
		u--;
		v--;
		
		dist[u][v] = c;
		dist[v][u] = c;
	}
	
	for (int i=0; i<k; i++) {
		init();
		
		int w, u, v;
		cin>> w >> u >> v;
		u--;
		v--;
		
		if (w == 0) {
			dijkstra(u, v);
			cout<< d[v];
		}
		
		if (w == 1) {
			dijkstra(u, v);
			list<int> shortestPath;
			shortestPath.clear();
			while (u!=v) {
				shortestPath.push_back(v);
				v = trace[v];
			}
			shortestPath.push_back(u);			
			cout << shortestPath.size() << " ";
			list<int>::iterator iter;
			for (iter = shortestPath.end(); iter != shortestPath.begin(); --iter) {
				cout << ((*iter) + 1) << " ";
			}
		}
	}
	return 0;
}
