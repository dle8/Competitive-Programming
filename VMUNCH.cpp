#include <bits/stdc++.h>
#define maxn 100+10
#define maxc 1000000000
using namespace std;

struct node {
	int v, next;
	int c = 1;
};
int r, c;
node graph[4*100*maxn];
bool check[100*maxn];
int head[100*maxn], d[100*maxn];
char a[maxn][maxn];
int s;

class pq {
	public: 
		int heap[100*maxn], cs[100*maxn], heapSize;
	
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
	
	int peek() {
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
	
	void downHeap(int index) {
		int temp = heap[index];
		while (true) {
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
	for (int i=1; i<=r; i++) 
		for (int j=1; j<=c; j++) 
			d[(i-1)*c+j] = maxc;
	
	d[s] = 0;
	pq q;
	q.init();
	q.update(s);
	memset(check, true, sizeof(check));
	while (!q.empty()) {
		int u = q.peek();
		q.poll();
		check[u] = false;
		if (u==1) break;
		int i = head[u];
		while (i!=0) {
			int v = graph[i].v;
			if (check[v] && d[v]>d[u]+graph[i].c) {
				d[v] = d[u]+graph[i].c;
				q.update(v);
			}
			i = graph[i].next;
		}
	}
	cout << d[1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dem, temp;
	cin >> r >> c;
	for (int i=1; i<=r; i++) {
		a[i][c+1] = '*';
		a[i][0] = '*';	
	}
	for (int j=1; j<=c; j++) {
		a[0][j] = '*';
		a[r+1][j] = '*';
	}
	
	dem = 0;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=r; i++)
		for (int j=1; j<=c; j++) {
			cin >> a[i][j];
			if (a[i][j]=='C') s = (i-1)*c+j;
			if (a[i][j]=='.' || a[i][j]=='B' || a[i][j]=='C') {
				temp = (i-1)*c+j;
				if (a[i-1][j]=='.' || a[i-1][j]=='B' || a[i-1][j]=='C') {
					dem++;
					graph[dem].v = (i-1-1)*c+j;
					graph[dem].next = head[temp];
					head[temp] = dem;
					
					dem++;
					graph[dem].v = temp;
					graph[dem].next = head[(i-2)*c+j];
					head[(i-2)*c+j] = dem;
				}
				if (a[i][j-1]=='.' || a[i][j-1]=='B' || a[i][j-1]=='C') {
					dem++;
					graph[dem].v = (i-1)*c+j-1;
					graph[dem].next = head[temp];
					head[temp] = dem;
					
					dem++;
					graph[dem].v = temp;
					graph[dem].next = head[(i-1)*c+j-1];
					head[(i-1)*c+j-1] = dem;
				}
			}
		}
	dijkstra(s);
	return 0;
}
