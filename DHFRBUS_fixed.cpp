#include <iostream>
#include <string.h>
#define maxn 100000+10
#define maxm 100000+10
#define maxk 5+5
#define maxc 1000000000000000
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<long, long> pll;
typedef long long ll;

struct node {
	long v, next;
	ll c;
};

node graph[2*maxm];
long n, k, s, t, m, head[maxn], heapSize, cs[maxn][maxk];
bool check[maxn][maxk];
ll d[maxn][maxk];
pll heap[5*maxn+10];

ll min(ll a, ll b) {
	if (a<=b) return a;
	else return b;
}

void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
}
	
void upHeap(long index) {
	pll temp = heap[index];
	while (true) {
		long parent = index/2;
		if (parent==0 || d[heap[parent].x][heap[parent].y]<=d[temp.x][temp.y]) break;
		heap[index] = heap[parent];
		cs[heap[index].x][heap[index].y] = index;
		index = parent; 
	}
	heap[index] = temp;
	cs[heap[index].x][heap[index].y] = index;
}
	
void update(pll u) {
	if (cs[u.x][u.y]==0) {
		heapSize++;
		heap[heapSize] = u;
		cs[u.x][u.y] = heapSize;
	}
	upHeap(cs[u.x][u.y]);
}

pll peek() {
	return heap[1];
}

bool empty() {
	return (heapSize==0);
}


void downHeap(long index) {
	pll temp = heap[index];
	while (true) {
		long child = index*2;
		if (child<heapSize && d[heap[child].x][heap[child].y]>d[heap[child+1].x][heap[child+1].y]) child++;
		if (child>heapSize || d[temp.x][temp.y]<=d[heap[child].x][heap[child].y]) break;
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
	long v;
	ll res;
	pll u;
	init();
	for (int i=1; i<=n; i++)
	for (int j=0; j<=k; j++) {
		check[i][j] = true;
		d[i][j] = maxc;
	}
	d[s][0] = 0;
	update(mp(s, 0));
	while (!empty()) {
		u = peek();
		poll();
		check[u.x][u.y] = false;
		
		long i = head[u.x];
		while (i!=0) {
			v = graph[i].v;
			for (int j=0; j<=1; j++) {
				if (u.y+(1-j)<=k && check[v][u.y+(1-j)] && d[v][u.y+(1-j)]>d[u.x][u.y]+graph[i].c*j) {
					d[v][u.y+(1-j)] = d[u.x][u.y]+graph[i].c*j;
					update(mp(v, u.y+(1-j)));
				}
			}
			i = graph[i].next;
		}
	}
	
	res = maxc;
	for (int i=0; i<=k; i++)
		res = min(res, d[t][i]);
	cout << res;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v; 
	ll c;
	cin >> n >> m >> k >> s >> t;
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
	return 0;
}
