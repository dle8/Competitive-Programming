/*
Tim k duong di ngan nhat khong giong nhau hoan toan tu thanh pho 1->n ung dung dijkstra
*/
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define maxm 4000+10
#define maxn 800+10
#define maxk 20+10
#define maxc 1000000000
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<long, long> pll;

long d[maxk][maxn];

struct node {
	int v, c, next;
};

struct compare {
	bool operator()(const pll&a, pll&b) {
		return (d[a.x][a.y]>d[b.x][b.y]);
	}
};

long k, n, m, head[maxn];
node graph[2*maxm];
priority_queue<pll, vector<pll>, compare> q;
pll trace[maxk][maxn];
bool check[maxk][maxn], inQueue[maxk][maxn];

void dijkstra() {
	long res;
	pll u;
	//d[t, i] la duong di ngan nhat thu t tu 1 den i
	for (int t=1; t<=k; t++)
	for (int i=1; i<=n; i++) {
		d[t][i] = maxc;
		check[t][i] = true;
		inQueue[t][i] = false;	
	}
	
	d[1][1] = 0;
	q.push(mp(1, 1));
	inQueue[1][1] = true;
	d[1][n+1] = maxc;
	while (!q.empty()) {
		//them 1 ptu de queue adjust
		q.push(mp(1, n+1));
		q.pop();
		//---//
		u = q.top();
		q.pop();
		inQueue[u.x][u.y] = false;
		check[u.x][u.y] = false;
		
		int i = head[u.y];
		while (i!=0) {
			long v = graph[i].v;
			for (int j=1; j<=k; j++) {
				if (check[j][v] && d[j][v]>d[u.x][u.y]+graph[i].c) {
					for (int t=k; t>=(j+1); t--) d[t][v] = d[t-1][v];
					d[j][v] = d[u.x][u.y]+graph[i].c;
					trace[j][v] = u;
					if (!inQueue[j][v]) {
						q.push(mp(j,v));
						inQueue[j][v] = true;
					}
				}
			}
			i = graph[i].next;
		}
	}
	res = 0;
	for (int i=1; i<=k; i++) res+=d[i][n];
	cout << res << "\n";
	for (int i=1; i<=k; i++) {
		pll v = mp(i, n);
		while (trace[v.x][v.y].y!=0) {
			cout << v.y << " ";
			v = trace[v.x][v.y];
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, t;
	cin >> k >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v >> t;
		graph[2*i].v = v;
		graph[2*i].c = t;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].c = t;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	dijkstra();
	return 0;
}
