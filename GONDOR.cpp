#include <bits/stdc++.h>
#include <math.h>
#define maxn 100+10
#define maxm 15000
using namespace std;

struct node {
	int v, next;
	double c;	
};

int n;
node tree[maxm];
bool check[maxn];
double res[maxn];
int x[maxn], y[maxn], head[maxn], s[maxn];
int tower[maxn][maxn];

class pq {
	public:
		node heap[maxm];
		int heapSize;
		double time;
	
	void init() {
		heapSize = 0;
		time = 0.0;
	}
	
	void add(node x) {
		x.c+=time;
		heapSize++;
		heap[heapSize] = x;
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		node temp = heap[index];
		while (true) {
			int parent = index/2;
			if (parent==0 || heap[parent].c<=temp.c) break;
			heap[index] = heap[parent];
			index = parent;
		}
		heap[index] = temp;
	}
	
	node peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize==0);
	}
	
	void poll() {
		time = heap[1].c;
		heap[1] = heap[heapSize];
		heapSize--;
		downHeap(heapSize);
	}
	
	void downHeap(int index) {
		node temp = heap[index];
		while (true) {
			int child = index*2;
			if (child<heapSize && heap[child].c>heap[child+1].c) child++;
			if (child>heapSize || temp.c<=heap[child].c) break;
			heap[index] = heap[child];
			index = child;
		}
		heap[index] = temp;
	}
};

double dist(int i, int j) {//distance between (xi, yi) and (xj, yj)
	return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}

void process() {
	int litTower;
	node root, u;
	pq q;
	q.init();
	memset(check, true, sizeof(check));
	root.v = 1;
	root.c = 0;
	q.add(root);
	while (true) {
		while (!q.empty() && !check[q.peek().v]) q.poll();
		if (q.empty()) break;	
		u = q.peek();
		q.poll();
		res[u.v] = u.c;
		check[u.v] = false;
		litTower = 0;
		int i = head[u.v];
		while (i!=0) {
			if (check[tree[i].v]) {
				q.add(tree[i]);
				litTower++;	
			}
			if (litTower==s[u.v]) break;
			i = tree[i].next;
		}
	}
	
	for (int i=1; i<=n; i++) 
		cout << res[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int inp, pos, dem;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
		cin >> s[i];
		for (int j=1; j<=(n-1); j++) cin >> tower[i][j];
	}
	dem = 0;
	for (int i=1; i<=n; i++) {
		for (int j=(n-1); j>=1; j--) {
			dem++;
			tree[dem].v = tower[i][j];
			tree[dem].c = dist(i, tower[i][j]);
			tree[dem].next = head[i];
			head[i] = dem;
		}
	}
	memset(res, 0, sizeof(res));
	process();
	return 0;
}
