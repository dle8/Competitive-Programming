#include <bits/stdc++.h>
#include <string.h>
#define maxm 100000+10
#define maxn 10000+10
using namespace std;

struct edge {
	int v, c, next;
};

edge road[2*maxm];
int ds[maxn], dt[maxn], headxuoi[maxn], headnguoc[maxn], d[maxn];
bool check[maxn];
int n, m, k;

class pq {
	public:
		int heap[4*maxm], indexOf[maxn];
		int heapSize;
	
	void init() {
		heapSize = 0;
		memset(indexOf, 0, sizeof(indexOf));
	}
	
	void add(int k) {
		if (indexOf[k]==0) {
			heap[++heapSize] = k;
			indexOf[k] = heapSize;
		}
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		long tmp = heap[index];
		while (true) {
			long parent = index/2;//the index of the parent node
			if ((parent == 0) || d[heap[parent]]<=d[tmp]) break;
			heap[index] = heap[parent];
			indexOf[heap[index]] = index;
			index = parent;
		}
		heap[index] = tmp;
		indexOf[heap[index]] = index;
	}
	
	int peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize == 0);
	}
	
	void poll() {
		indexOf[heap[1]] = 0;
		heap[1] = heap[heapSize--];
		indexOf[heap[1]] = 1;
		downHeap(1);
	}
	
	void downHeap(int index) {
		long tmp = heap[index];
		while (true) {
			long child = index*2;//left child
			if (child<heapSize && d[heap[child]]>d[heap[child+1]]) child++;//choose the smallest child among the two
			if (child>heapSize || d[tmp]<=d[heap[child]]) break;
			heap[index] = heap[child];
			indexOf[heap[index]] = index;
			index = child;
		}
		heap[index] = tmp;
		indexOf[heap[index]] = index;
	}
};

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

inline void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void update(int u, int v, int c) {
	if (d[v] > d[u] + c) 
		d[v] = d[u] + c;
}

void dijkstra(int u, int head[]) {
	int k, end;
	for (int i=1; i<=n; i++) d[i] = 1000000000;
	memset(check, true, sizeof(check));
	d[u] = 0;
	pq queue;
	queue.init();//reinitia
	queue.add(u);
	while (!queue.empty()) {
		k = queue.peek();
		queue.poll();
		check[k] = false;
		int i = head[k];
		while (i!=0) {
			end = road[i].v;
			if (check[end]) {
				update(k, end, road[i].c);
				queue.add(end);
			}
			i = road[i].next;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int s, t, u, v, c, minPath, test;
	cin >> test;
	for (int bien=1; bien<=test; bien++) {
		cin >> n >> m >>k >> s>> t;
		memset(headxuoi, 0, sizeof(headxuoi));
		memset(headnguoc, 0, sizeof(headnguoc));
		for (int i=1; i<=m; i++){
			cin >> u >> v >> c;
			road[2*i].v = v;
			road[2*i].c = c;
			road[2*i].next = headxuoi[u];
			headxuoi[u] = 2*i;
			
			road[2*i+1].v = u;
			road[2*i+1].c = c;
			road[2*i+1].next = headnguoc[v];
			headnguoc[v] = 2*i+1;
		}
		for (int i=1; i<=n; i++) dt[i] = 1000000010;
		minPath = 1000000000;
		dijkstra(s, headxuoi);//dijkstra xuoi tu u de lay mang ds;
		for (int i=1; i<=n; i++) 
			ds[i] = d[i];
		minPath = d[t];
		
		dijkstra(t, headnguoc);//dijkstra nguoc tu t de lay mang dt;
		for (int i=1; i<=n; i++)
			dt[i] = d[i];

		for (int i=1; i<=k ;i++) {
			cin >> u >> v >> c;
			minPath = min(minPath, min(ds[u]+c+dt[v], ds[v]+c+dt[u]));
		}
		if (minPath == 1000000000) cout << -1 << endl;
		else cout << minPath << endl;	
	}
	return 0;
}
