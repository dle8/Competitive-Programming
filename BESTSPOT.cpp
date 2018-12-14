#include <bits/stdc++.h>
#include <queue>
#define maxc 1000000000
#define maxn 500+10
#define maxm 8000+10
using namespace std;

struct node {
	int v, c, next;
};

node graph[2*maxm]; 
long head[maxn], d[maxn], f[maxn];
bool check[maxn];
long p, m, c;

class pq {
	public:
		long heap[maxn], cs[maxn], heapSize;
	
	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}
	
	void update(int u) {
		if (cs[u]==0) {
			heapSize++;
			heap[heapSize] = u;
			cs[heap[heapSize]] = heapSize; 
		}
		upHeap(cs[u]);
	}
	
	void upHeap(int index) {
		long temp = heap[index];
		while (true) {
			long parent = index/2;
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
 		}
		heap[index]	= temp;
		cs[heap[index]] = index;
	}
	
	long peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize==0);
	}
	
	void poll() {
		cs[heap[1]] = 0;
		cs[heap[heapSize]] = 1;
		heap[1] = heap[heapSize];
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int temp = heap[index];
		while (true) {
			int child = index*2;
			if  (child<heapSize && d[heap[child]]>d[heap[child+1]]) child++;
			if (child>heapSize || d[temp]<=d[heap[child]]) break;
			heap[index] = heap[child];
			cs[heap[index]] = index;
			index = child;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
	
};

pq q;

long dijkstra(long s, long t) {
	long v, u;
	if (s==t) return 0;
	for (int i=1; i<=p; i++) {
		d[i] = maxc;
		check[i] = true;	
		q.cs[i] = 0;
	}
	q.heapSize = 0;
	d[s] = 0;
	q.update(s);
	while (!q.empty()) {
		u = q.peek();
		q.poll();
		check[u] = false;
		if (u==t) break;
		int i = head[u];
		while (i!=0) {
			v = graph[i].v;
			if (check[v] && d[v]>d[u]+graph[i].c) {
				d[v] = d[u]+graph[i].c;
				q.update(v);
			}
			i = graph[i].next;
		}
	}
	return d[t];
}

void process() {
	bool flag;
	long sum, dist, minSum, res;
	minSum = maxc;
	sum = 0;
	for (int i=1; i<=p; i++) {
		sum = 0;
		flag = true;
		for (int j=1; j<=m; j++) {
			dist = dijkstra(i, f[j]);
			if (dist==maxc) flag = false;
			if (flag) sum+=dist;
			else break;
		}
		if (minSum>sum && flag) {
			minSum = sum;
			res = i;
		}
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, t, dem;
	cin >> p >> m >> c;
	for (int i=1; i<=m; i++) cin >> f[i];
	
	dem = 0;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=c; i++) {
		cin >> u >> v >> t;
		dem++;
		graph[dem].v = v;
		graph[dem].c = t;
		graph[dem].next = head[u];
		head[u] = dem;
		
		dem++;
		graph[dem].v = u;
		graph[dem].c = t;
		graph[dem].next = head[v];
		head[v] = dem;
	}	
	process();	
	return 0;
}
