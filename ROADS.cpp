#include <bits/stdc++.h>
#include <queue>
#include <vector>
#define maxn 100+10
#define maxr 10000+10
#define maxc 1000000000
#define maxk 10000+10
#define x first
#define y second
#define mp make_pair	

using namespace std;

typedef pair<int, int> ii;

struct node {
	int v, c, t, next;
};

int n, k;
node graph[maxr];
int head[maxn], d[maxn][maxk];
bool check[maxn][maxk];
ii heap[100*maxk];
int cs[maxn][maxk];
int heapSize;

int min (int a, int b) {
	if (a<=b) return a;
	else return b;
}

bool smaller(ii a, ii b) {
	return (d[a.x][a.y]<=d[b.x][b.y]);
}

void init() {
	heapSize = 0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=k; j++) 
		cs[i][j] = 0;
}

bool empty() {
	return (heapSize==0);
}
	
ii peek() {
	return heap[1];
}
	
void upHeap(int index) {
	ii temp = heap[index];
	while (true) {
		int parent = index/2;
		if (parent==0 || smaller(heap[parent], temp)) break;
		heap[index] = heap[parent];
		cs[heap[index].x][heap[index].y] = index;
		index = parent;
	}
	heap[index] = temp;
	cs[heap[index].x][heap[index].y] = index;
}

void update(ii u){
	if (cs[u.x][u.y]==0) {
		heapSize++;
		heap[heapSize] = u;
		cs[u.x][u.y] = heapSize;
	}
	upHeap(cs[u.x][u.y]);
}

void downHeap(int index) {
	ii temp = heap[index];
	while (true) {
		int child = index*2;
		if (child<heapSize && !smaller(heap[child], heap[child+1])) child++;
		if (child>heapSize || smaller(temp, heap[child])) break;
		heap[index] = heap[child];
		cs[heap[index].x][heap[index].y] = index;
		index = child;
	}
	heap[index] = temp;
	cs[heap[index].x][heap[index].y] = index;
}

void poll() {
	cs[heap[1].x][heap[1].y] = 0;
	heap[1] = heap[heapSize];
	cs[heap[1].x][heap[1].y] = 1;
	heapSize--;
	downHeap(1);
}

void dijkstra() {
	ii u;
	int v;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=k; j++) {
			d[i][j] = maxc;
			check[i][j] = true;	
		}
	d[1][0] = 0;
	init();
	update(mp(1, 0));
	while (!empty()) {
		u = peek();
		poll();
		check[u.x][u.y] = false;
		int i = head[u.x];
		while (i!=0) {
			v = graph[i].v;
			if (u.y+graph[i].t<=k && check[v][u.y+graph[i].t] && d[v][u.y+graph[i].t]>d[u.x][u.y]+graph[i].c) {
				d[v][u.y+graph[i].t] = d[u.x][u.y]+graph[i].c;
				update(mp(v, u.y+graph[i].t));
			}
			i = graph[i].next;
		}
	}
	
	int res = maxc;
	for (int i=0; i<=k; i++) 
		res = min(res, d[n][i]);
	if (res==maxc) cout << -1 << "\n";
	else cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test, r, s, d, l, t;
	cin >> test;
	for (int i=1; i<=test; i++) {
		cin >> k >> n >> r;
		memset(head, 0, sizeof(head));
		for (int j=1; j<=r; j++) {
			cin >> s >> d >> l >> t;
			graph[j].v = d;
			graph[j].c = l;
			graph[j].t = t;
			graph[j].next = head[s];
			head[s] = j;
		}
		dijkstra();
	}
	return 0;
}
