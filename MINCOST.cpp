#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#define maxll 1000000000000000
#define maxlong 1000000000
#define maxn 100+10
#define maxm 10000+10
#define debugi(s) cout << "enter " << s << "\n"
#define debugo(s) cout << "exit " << s << "\n"
using namespace std;
typedef long long ll;
typedef pair<pair<int, int>, int> ppii;

struct node {
	long v, next;
	ll c, d;
};

long n, k, s, t, inStock;
ll dist[maxn], f[maxn][maxn], trace[maxn], head[maxn], d[maxn][maxn], c[maxn][maxn];
node graph[2*100*maxn];

void read() {
	long m, u, v;
	cin >> n >> m >> k >> s >> t;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
		
		cin >> c[u][v] >> d[u][v];
		d[v][u] = d[u][v];
		c[v][u] = c[u][v]; 
	}
}

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

int getDirection(long flow) {
	if (flow>=0) return 1;//tai sao 
	else return -1;
}

bool findPath() {//timm duong tang luong CHUA BAO HOA co chi phi it nhat tu s->t su dung ford bellman
//	debugi("path");
	long v;
	bool updating;
	for (int i=1; i<=n; i++) dist[i] = maxll;
	dist[s] = 0;
	do {
		updating = false;
		for (int u=1; u<=n; u++) {
			int i = head[u];
			while (i!=0) {
				v = graph[i].v;
				if (d[u][v]-f[u][v]>0 && dist[v]>dist[u]+c[u][v]*getDirection(f[u][v])) {
						trace[v] = u;
						dist[v] = dist[u]+c[u][v]*getDirection(f[u][v]);
						updating = true;
					}
				i = graph[i].next;
			}
		}
	} while (updating);
//	debugo("path");
	if (dist[t]==maxll) return false;
	return true;
}

long findMaxFlow(long remainGoods) {//tim luong luong nhieu nhat co the di qua duong di nho nhat vua tim duoc
	long maxFlow = maxlong;
	long v = t;
	while (v!=s) {
		long u = trace[v];
		maxFlow = min(maxFlow, d[u][v]-f[u][v]);
		v = u;
	}
	return min(maxFlow, remainGoods);
}

void updateFlow(long flow) {
	long v = t;
	while (v!=s) {
		long u = trace[v];
		f[u][v]+=flow;
		f[v][u]-=flow;
		v = u;
	}
}

void process() {
	bool found;
	long deliveredGoods;
	for (int i=1; i<=n; i++)
		memset(f[i], 0, sizeof(f[i]));
	inStock = k;
	while (true) {
		found = findPath();
		if (!found) break;//neu het duong tang luong -> break
		deliveredGoods = findMaxFlow(inStock);
		updateFlow(deliveredGoods);
		inStock-=deliveredGoods;
		if (inStock==0) break;
	}
}

void print() {
	long count = 0, v;
	ll totalCost = 0;
	ppii res[maxm];
	//pair<int, int> res[maxm];
	if (inStock>0) {
		cout << -1;
		return;
	}
	
	for (int u=1; u<=n; u++) {
		int i = head[u];
		while (i!=0) {
			v = graph[i].v;
			if (f[u][v]>0) {
				totalCost+=(f[u][v]*c[u][v]);
				count++;
				res[count].first.first = u;
				res[count].first.second = v;
				res[count].second = f[u][v];
			}
			i = graph[i].next;
		}
	}
	
	cout << totalCost << "\n";
	for (int i=1; i<=count; i++) 
		cout << res[i].first.first << " " << res[i].first.second << " " << res[i].second << "\n";
	
	cout << "0 0 0";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	read();
	process();
	print();
	return 0;
}
