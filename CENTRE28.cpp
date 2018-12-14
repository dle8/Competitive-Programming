#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#include <utility>
#define maxn 30000+10
#define maxm 100000+10
#define maxc 1000000000
using namespace std;

struct node {
	long v, c, next;
};

long d[maxn], head[maxn], path[maxn];
long n, m;
bool check[maxn], thirdcity[maxn];
node graph[2*maxm];

bool increase(const long&a, const long&b) {
	return d[a]<d[b];
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
			if (parent==0 || d[heap[parent]]<d[temp]) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
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
	
	long peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize==0);
	}
};

void dijkstra() {
	long u, v;
	pq q;
	q.init();
	d[1] = 0;
	q.update(1);
	
	for (int i=2; i<=n; i++) {
		d[i] = maxc;	
		q.update(i);
	}
	
	while (!q.empty()) {
		//
		u = q.peek();
		q.poll();
		
		long i = head[u];
		while (i!=0) {
			v = graph[i].v;
			if (d[v]>d[u]+graph[i].c) {
				d[v] = d[u]+graph[i].c;
				q.update(v);	
			}
			i = graph[i].next;
		}
	}
}

void countThirdCities() {//bfs
	long count = 0, first = 1, last = 1, u, v, indexMax, maxd, res, temp, index, dem;
	memset(check, true, sizeof(check));
	memset(thirdcity, false, sizeof(thirdcity));
	check[n] = false;
	path[first] = n;
	while (first<=last) {
		v = path[first];
		first++;
		long i = head[v];
		while (i!=0) {
			u = graph[i].v;
			if (check[u] && d[v]==d[u]+graph[i].c){
				check[u] = false;
				last++;			
				path[last] = u;
			}
			i = graph[i].next;	
		}
	}
	count=last;
	sort(path+1, path+count+1, increase);
	maxd = -maxc;
	
	for (int i=1; i<count; i++) {
		index = head[path[i]];
		while (index!=0) {
			v = graph[index].v;
			if (!check[v] && d[v]==(d[path[i]]+graph[index].c)) {
				if (maxd == d[v] && indexMax!=v) dem++;
				if (maxd<d[v]) {
					maxd = d[v];
					indexMax = v;
					dem = 1;
				}
			}
			index = graph[index].next;
		}
		if (maxd>=d[path[i+1]] && (indexMax!=path[i+1] || dem>1)) thirdcity[path[i+1]] = true;
	}
	res = 0;
	for (int i=2; i<=n-1; i++) 
	if (thirdcity[i] || check[i]) res++;
	cout << res << "\n";
	
	for (int i=2; i<=n-1; i++) 
	if (thirdcity[i] || check[i]) cout << i << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, c;
	cin >> n >> m;
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
	dijkstra();
	countThirdCities();
	return 0;
}
