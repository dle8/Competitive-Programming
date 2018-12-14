#include <iostream>
#include <list>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int n, m, k;
int dist[100][100];
int trace[100][100];


void init() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i==j) dist[i][j] = 0;
			else dist[i][j] = 1000000000;
			trace[i][j] = -1;
		}
	}
}

void floyd() {
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					trace[i][j] = trace[i][k];
				}
			}
		}
	}
}

int main(int argc, char** argv) {

	cin>>n >> m >>k;
	
	init();
	for (int i=0; i<m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		
		dist[u][v] = c;
		dist[v][u] = c;
		
		trace[u][v] = v;
		trace[v][u] = u;
	}
	
	floyd();
	
	for (int i=0; i<k; i++) {
		int w, u, v;
		cin >> w >> u >> v;
		u--;
		v--;
		
		if (w == 0) {
			cout << dist[u][v];
		}
		
		if (w == 1) {
			list<int> path;
			path.clear();
			while ( u!= v) {
				path.push_back(u);
				u = trace[u][v];
			}
			path.push_back(v);
			cout << path.size() << " ";
			list<int>::iterator iter;
			for (iter = path.begin(); iter != path.end(); ++iter) {
				cout << ((*iter) + 1) << " ";
			}
		}
	}
		
	return 0;
}
