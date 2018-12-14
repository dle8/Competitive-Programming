#include <iostream>
#include <queue>
#include <string.h>
#define maxn 100000+10
#define maxm 100000+10
#define maxk 5+5
#define maxc 1000000000000000000
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<long, long> pll;

struct node {
	long v, next;
	long long c;
};

long long d[maxn][maxk];

struct compare {
	bool operator()(const pll&a, const pll&b) {
		return (d[a.x][a.y]>d[b.x][b.y]);
	}
};

node graph[2*maxm];
long n, k, s, t, m, head[maxn];
priority_queue<pll, vector<pll>, compare> q;
bool check[maxn][maxk], inQueue[maxn][maxk];

long long min(long long a, long long b) {
	if (a<=b) return a;
	else return b;
}

void dijkstra() {
	long v;
	long long res;
	pll u;
	for (int i=1; i<=n; i++)
	for (int j=0; j<=k; j++) {
		d[i][j] = maxc;
		check[i][j] = true;
		inQueue[i][j] = false;	
	}
	d[s][0] = 0;
	q.push(mp(s, 0));
	check[s][0] = false;
	inQueue[s][0] = true;
	d[n+1][0] = -maxc;
	while (!q.empty()) {
		q.push(mp(n+1, 0));
		q.pop();
		
		u = q.top();
		q.pop();
		check[u.x][u.y] = false;
		inQueue[u.x][u.y] = false;
		
		int i = head[u.x];
		while (i!=0) {
			v = graph[i].v;
			for (int j=0; j<=1; j++) {
				if (u.y+(1-j)<=k && check[v][u.y+(1-j)] && d[v][u.y+(1-j)]>d[u.x][u.y]+graph[i].c*j) {
					d[v][u.y+(1-j)] = d[u.x][u.y]+graph[i].c*j;
					if (!inQueue[v][u.y+(1-j)]) {
						q.push(mp(v, u.y+(1-j)));
						inQueue[v][u.y+(1-j)] = true;
					}
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
	long long c;
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
