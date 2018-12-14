#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define maxn 5000+10
#define maxm 20000+10
#define maxc 1000000000
using namespace std;

struct node {
	long v, c, next;
};

long d[maxn];
long long f[maxn];

struct compare {
	bool operator()(const long&a, const long&b) {
		return (d[a]>d[b]);
	}
};

node graph[2*maxm];
long n, head[maxn];
priority_queue<long, vector<long>, compare> q;
bool inQueue[maxn], check[maxn];

void dijkstra() {
	long u, v;
	memset(check, true, sizeof(check));
	memset(inQueue, false, sizeof(inQueue));
	for (int i=1; i<=n; i++) d[i] = maxc;
	d[1] = 0;
	f[1] = 1;
	q.push(1);
	inQueue[1] = true;
	check[1] = false;
	d[n+1] = -maxc;
	while (!q.empty()) {
		//add them 1 node de adjust queue
		q.push(n+1);
		q.pop();
		//
		u = q.top();
		q.pop();
		inQueue[u] = false;
		check[u] = false;
		long i = head[u];
		while (i!=0) {
			v = graph[i].v;
			if (check[v]) {
				if (d[v]>d[u]+graph[i].c) {
					d[v] = d[u]+graph[i].c;
					f[v] = f[u];
					if (!inQueue[v]) {
						q.push(v);
						inQueue[v] = true;
					}
				}
				else if (d[v]==d[u]+graph[i].c) f[v]+=f[u];
			}
			i = graph[i].next;
		}
	}
	
	cout << d[n] << " " << f[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long k, u, v, l, m, count;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> k >> u >> v >> l;
		graph[2*i].v = v;
		graph[2*i].c = l;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		if (k==1) continue;
		graph[2*i+1].v = u;
		graph[2*i+1].c = l;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	dijkstra();
	return 0;
}
