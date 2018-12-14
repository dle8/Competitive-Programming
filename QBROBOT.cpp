#include <bits/stdc++.h>
#define maxn 500+10
#define maxm 30000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxc 1000000000
using namespace std;

struct node {
	long v, t, c, next;
};

node graph[2*maxm];
long d[maxn], minCost, n, head[maxn];
bool ps[maxn];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

class pq {
	public:
		long heap[maxn], cs[maxn], heapSize;
	
	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
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
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
		}
		heap[index] = temp;
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
		heap[1] = heap[heapSize];
		cs[heap[1]] = 1;
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(long index) {
		long temp = heap[index];
		while (true) {
			long child = index*2;
			if (child<heapSize && d[heap[child]]>d[heap[child+1]]) child++;
			if (child>heapSize || d[temp]<=d[heap[child]]) break;
			heap[index] = heap[child];
			cs[heap[index]] = index;
			index = child;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
};

void dijkstra() {
	pq q;
	q.init();
	FOR(i, 1, n) {
		d[i] = maxc;
		q.update(i);
	}
	d[1] = 0;
	q.update(1);
	while (!q.empty()) {
		long u = q.peek();
		q.poll();
		
		long i = head[u];
		while (i!=0) {
			long v = graph[i].v;
			if (d[v]>d[u]+graph[i].t) {
				d[v] = d[u]+graph[i].t;
				q.update(v);
			}
			i = graph[i].next;
		}		
	}
}

void dfs(long v, long roadCost, long maxdoan) {
	long u;
	if (v==1) {
		maxdoan = max(maxdoan, roadCost);
		minCost = min(minCost, maxdoan);
	}
	long i = head[v];
	while (i!=0) {
		u = graph[i].v;
		if (d[v]==d[u]+graph[i].t) {
			if (ps[v]) dfs(u, graph[i].c, max(maxdoan, roadCost));
			else dfs(u, roadCost+graph[i].c, maxdoan);
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long pw, u, v, t, c, m;
	cin >> n;
	memset(ps, false, sizeof(ps));
	FOR(i, 1, n) {
		cin >> pw;
		if (pw==1) ps[i] = true;
	}
	cin >> m;
	FOR(i, 1, m) {
		cin >> u >> v >> t >> c;
		graph[2*i].v = v;
		graph[2*i].t = t;
		graph[2*i].c = c;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].t = t;
		graph[2*i+1].c = c;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	
	dijkstra();
	minCost = maxc;
	dfs(n, 0, -maxc);
	cout << minCost;
	return 0;
}
