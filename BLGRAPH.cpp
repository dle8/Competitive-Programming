#include <bits/stdc++.h>
#define maxn 10000+10
using namespace std;

struct node {
	long v, next;
};

node graph[2*maxn];
bool check[maxn];
long c[maxn], head[maxn], deg[maxn], n, chonto[maxn];

bool smaller(long u, long v) {
	if (check[u] && !check[v]) return true;
	return false;
//	if (check[v] && !check[u]) return false;
}

class pq {
	public:
		long heap[maxn], cs[maxn];
		long heapSize;
	
	void init() {
		memset(cs, 0, sizeof(cs));
		heapSize = 0;
	}

	void update(long u) {
		if (cs[u]==0) {
			heapSize++;
			heap[heapSize] = u;
			cs[heap[heapSize]] = heapSize;
		}
		upHeap(cs[u]);
	}
	
	void upHeap(long index) {
		long temp = heap[index];
		while (true) {
			long parent = index/2;
			if (parent==0 || (check[heap[parent]] && deg[heap[parent]]>=deg[temp])) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
	
	bool empty() {
		return (heapSize==0 || !check[heap[1]]);
	}
	
	long peek() {
		if (empty()) return 0;
		else return (heap[1]);
	}
	
	void poll() {
		cs[heap[1]] = 0;
		heap[1] = heap[heapSize];
		cs[heap[1]] = 1;
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(long index) {
		long temp = heap[index];
		while (true) {
			long child = 2*index;
			if (child<heapSize && (smaller(heap[child], heap[child+1]) || deg[heap[child]]<deg[heap[child+1]])) child++;
			if (child>heapSize || smaller(heap[child], temp) || deg[temp]>=deg[heap[child]]) break;
			heap[index] = heap[child];
			cs[heap[index]] = index;
			index = child;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}

};

void process() {
	pq q;
	q.init();
	long color = 0, count = 0;
	long u, v, sum;
	memset(c, 0, sizeof(c));
	memset(check, true, sizeof(check));
	memset(chonto, 0, sizeof(chonto));
	for (int i=1; i<=n; i++) q.update(i);
	while (true) {
		u = 0;
		u = q.peek();
		if (u==0) break;
		color++;
		count = 0;
		while (true) {
			v = q.peek();
			if (!q.empty()) q.poll();
			if (v==0) break;
			c[v] = color;
			count++;
			chonto[count] = v;
			int i = head[v];
			while (i!=0) {
				long k = graph[i].v;
				check[k] = false;
				i = graph[i].next;
			}				
		}
		for (int i=1; i<=count; i++) {
			long j = head[chonto[i]];
			while (j!=0) {
				long k = graph[j].v;
				check[k] = true;
				j = graph[j].next;
			}
		}
	}
	/*sum = 0;
	for (int i=1; i<=n; i++) sum+=(color+1-c[i]);
	cout << sum << "\n";
	for (int i=1; i<=n; i++) cout << i << " "  <<color+1-c[i] << "\n";*/
	for (int i=1; i<=n; i++) cout << c[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u,v, m;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
		
		deg[u]++;
		deg[v]++;
	}
	process();
	return 0;
}
