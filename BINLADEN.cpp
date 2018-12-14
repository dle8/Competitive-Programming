#include <bits/stdc++.h>
#include <string>
#define maxn 25000
using namespace std;

struct node {
	int v, next, c;
};

node tree[4*maxn];
bool check[maxn];
int head[maxn];
long long d[maxn];
int n, m;

class priorityQueue {
	public:
		int heap[maxn], cs[maxn];
		int heapSize;
		
	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}
	
	bool empty() {
		return (heapSize==0);
	}
	
	int peek() {
		return heap[1];
	}
	
	void update(int x) { 
		if (cs[x]==0) {
			heapSize++;
			heap[heapSize] = x;
			cs[heap[heapSize]] = heapSize;	
		}
		upHeap(cs[x]);
	}
	
	void upHeap(int index) {
		int temp = heap[index];
		while (true) {
			int parent = index/2;
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
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
	
	void downHeap(int index) {
		int temp = heap[index];
		while (true){
			int child = index*2;
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

void dijkstra(int s) {
	int u, v;
	for (int i=1; i<=(m*n+1); i++) 
		d[i] = 1000000000;
	d[s] = 0;
	priorityQueue q;
	q.init();
	q.update(s);
	while (!q.empty()) {
		u = q.peek();
		q.poll();
		check[u] = false;
		int i = head[u];
		while (i!=0) {
			v = tree[i].v;
			if (check[v]) {
				if (d[v]>d[u]+tree[i].c) d[v] = d[u] + tree[i].c;
				q.update(v);
			}
			i = tree[i].next;
		}
	}
	cout << d[m*n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k, root, dem, c;
	cin >> m >> n;//m dong n cot
	root = 0;
	dem = 0;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=(2*m); i++) {
		if (i%2!=0) {
			k = (i+1)/2;
			for (int j=1; j<=n; j++) {
				cin >> c;
				if (k==1) {
					dem++;
					tree[dem].v = (k-1)*n+j;
					tree[dem].c = c;
					tree[dem].next = head[root];
					head[root] = dem;
				}
				
				if (k!=1) {
					dem++;
					tree[dem].v = (k-1)*n+j;
					tree[dem].c = c;
					tree[dem].next = head[(k-2)*n+j];
					head[(k-2)*n+j] = dem;
					
					dem++;
					tree[dem].v = (k-2)*n+j;
					tree[dem].c = c;
					tree[dem].next = head[(k-1)*n+j];
					head[(k-1)*n+j] = dem;
				}
			}
		}
		else {//if (i%2==0)
			k = i/2;
			for (int j=1; j<=(n-1); j++) {
				cin >> c;
				
				dem++;
				tree[dem].v = (k-1)*n+j;
				tree[dem].c = c;
				tree[dem].next = head[(k-1)*n+j+1];
				head[(k-1)*n+j+1] = dem;
				
				dem++;
				tree[dem].v = (k-1)*n+j+1;
				tree[dem].c = c;
				tree[dem].next = head[(k-1)*n+j];
				head[(k-1)*n+j] = dem;
			}
		}
	}
	memset(check, true, sizeof(check));
	dijkstra(root);
}
