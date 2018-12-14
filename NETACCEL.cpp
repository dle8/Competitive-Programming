#include <bits/stdc++.h>
#include <string.h>
#define maxm 100000+10
#define maxn 1000+10
#define maxk 10+5
using namespace std;

typedef pair<int, int> ii;

struct node {
	int v, next;
	double c;
};

int n, k;
node graph[2*maxm];
double d[maxn][maxk];
int head[maxn];
bool check[maxn][maxk];

double min(double a, double b) {
	if (a<=b) return a;
	else return b;
}

bool smaller(ii u, ii v) {
	if (d[u.first][u.second]<d[v.first][v.second]) return true;
	return false;
}

class pq {
	public: 
		ii heap[15*maxn];
		int cs[maxn][maxk];
		int heapSize;
	
	void init() {
		heapSize = 0;
		for (int i=1; i<=n; i++)
			for (int j=0; j<=k; j++)
				cs[i][j] = 0;
	}
	
	void update(ii p) {
		if (cs[p.first][p.second]==0) {
			heapSize++;
			heap[heapSize] = p;
			cs[p.first][p.second] = heapSize;
		}
		upHeap(cs[p.first][p.second]);
	}
	
	void upHeap(int index) {
		ii temp = heap[index];
		while (true) {
			int parent = index/2;
			if (parent ==0 || !smaller(temp, heap[parent])) break;
			heap[index] = heap[parent];
			cs[heap[index].first][heap[index].second] = index;
			index = parent;
		}
		heap[index] = temp;
		cs[heap[index].first][heap[index].second] = index;
	}
	
	ii peek() {
		return heap[1];
	}
	
	void poll() {
		cs[heap[1].first][heap[1].second] = 0;
		cs[heap[heapSize].first][heap[heapSize].second] = 1;
		heap[1] = heap[heapSize];
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		ii temp = heap[index];
		while (true) {
			int child = index*2;
			if (child<heapSize && smaller(heap[child+1], heap[child])) child++;
			if (child>heapSize || !smaller(heap[child], temp)) break;
			heap[index] = heap[child];
			cs[heap[index].first][heap[index].second] = index;
			index = child;
		}
		heap[index] = temp;
		cs[heap[index].first][heap[index].second] = index;
	}
	
	bool empty() {
		return (heapSize==0);
	}
};

void dijkstra() {
	int v;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=k; j++) d[i][j] = 1000000000000.0;
	
	d[1][0] = 0;
	pq q;
	q.init();
	q.update(make_pair(1, 0));
	while (!q.empty()) {
		ii u = q.peek();
		q.poll();
		check[u.first][u.second] = false;
		int i = head[u.first];
		while (i!=0) {
			v = graph[i].v;
			for (int j=0; j<=k; j++) {
				if (check[v][u.second+j] && u.second+j<=k && d[v][u.second+j]>d[u.first][u.second]+graph[i].c/(1<<j)) {
					d[v][u.second+j] = d[u.first][u.second] + graph[i].c/(1<<j);
					q.update(make_pair(v, u.second+j));
				}
			}
			i = graph[i].next;
		}
	}
	
	double res = 1000000000000.0;
	for (int i=0; i<=k; i++) {
		res = min(res, d[n][i]);
	}
	
	printf("%.2lf", res);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, u, v; 
	double c;
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> c;
		graph[2*i].v = v;
		graph[2*i].c = c;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].c = c;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;		
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=k; j++)
			check[i][j] = true;
	}
	dijkstra();
	return 0;
}
