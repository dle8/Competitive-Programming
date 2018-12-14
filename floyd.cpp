#include <iostream>
#include <string.h>

using namespace std;
int n;

struct edge {
	int v, c, next;
};

edge roads[(100+10)*(100+10)*2];
bool check[100+10];
int dist[100+10], path[100+10], head[100+10], trace[100+10];

void dijkstra(int u, int destination) {

	for (int i=1; i<=n; i++) {
		dist[i] = 1000000000;
		check[i] = true;
	}
	
	int min;
	int index, v;
	dist[u] = 0;
	
	while (true) {
		min = 1000000000;
		for (int i=1; i<=n; i++) 
			if (dist[i] < min && check[i]) {//tim thang gan u nhat ma chua tham
				min = dist[i];
				index = i;
			}
		
//		cout << index << endl;
		if (index == destination) break;
		check[index] = false;
				
		int i = head[index];
		while (i!=0) {
			v = roads[i].v;
			if (check[v] && (dist[v] > dist[index] + roads[i].c)) {
					dist[v] = dist[index] + roads[i].c;
					trace[v] = index;
				}
			i = roads[i].next;
		}
	}
}

int main() {
	int m, k;
	int w, u, v, c, sodinh;
	cin >> n >> m >> k;
	
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> c;
		
		roads[i*2].v = v;
		roads[i*2].c = c;
		roads[i*2].next = head[u];
		head[u] = 2*i;
		
		roads[2*i+1].v = u;
		roads[2*i+1].c = c;
		roads[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	
	for (int i=1; i<=k; i++) {
		cin >> w >> u >> v;
		if (w==0) {
			dijkstra(u, v);
			cout << dist[v] << endl;
		}
		
		if (w==1) {
			dijkstra(u, v);
			sodinh = 0;
			while (v!=u) {
				sodinh++;
				path[sodinh] = v;
				v = trace[v];
			}
			sodinh++;
			path[sodinh] = u;
			cout << sodinh << " ";
			for (int j = sodinh; j>=1; j--) cout << path[j] << " ";
			cout << endl;
		}
	}
	return 0;
}
