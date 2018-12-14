#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxn 10000+10
#define maxm 100000+10
using namespace std;

typedef pair<long, long> pll;

struct node {
	long u, v, c, pos;
	bool isBridge;
};

struct pnode {
	long v, next;
	bool selected;
};

pll cost[maxn];
node channel[maxm];
long tcount, number[maxn], low[maxn], n, head[maxn], parent[maxn],lab[maxn], a[maxn], b[maxn];
pnode graph[2*maxm];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void swap(long&a, long&b) {
	long temp = a;
	a = b;
	b = temp;
}

void dfs(long u) {
	tcount++;
	number[u] = tcount;
	low[u] = n+1;
	
	long i = head[u];
	while (i!=0) {
		if (!graph[i].selected) {
			if (graph[i+1].v==u) graph[i+1].selected = true;
			else graph[i-1].selected = true;
			long v = graph[i].v;
			if (parent[v]==0) {
				parent[v] = u;
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], number[v]);
		}		
		i = graph[i].next;
	}
}

bool compare(pll&x, pll&y) {
	return (x.first<y.first);	
}

bool compareChannel(const node&x, const node&y) {
	return (x.c<y.c);
}

long getRoot(long u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void dsu(long r1, long r2) {
	if (lab[r1]==lab[r2]) {
		lab[r2] = r1;
		lab[r1]--;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	long m, bridgeA, bridgeB, u, v, c, ttest;
	cin >> ttest;
	FOR(o, 1, ttest) {
		cin >> n >> m;
		FOR(i, 1, n) {
			lab[i] = -1;
			head[i] = 0;
		}
		FOR(i, 1, n-1) cin >> a[i];
		FOR(i, 1, n-1) cin >> b[i];	
		FOR(i, 1, m) {
			cin >> channel[i].u >> channel[i].v >> channel[i].c;
			channel[i].pos = i;
			channel[i].isBridge = false;
			graph[2*i].v = channel[i].v;
			graph[2*i].selected = false;
			graph[2*i].next = head[channel[i].u];
			head[channel[i].u] = 2*i;
			
			graph[2*i+1].v = channel[i].u;
			graph[2*i+1].selected = false;
			graph[2*i+1].next = head[channel[i].v];
			head[channel[i].v] = 2*i+1;
		}
		
		//tim cau
		tcount = 0;
		memset(parent, 0, sizeof(parent));
		FOR(i, 1, n) {
			if (parent[i]==0) {
				parent[i] = -1;
				dfs(i);
			}
		}
		
		bridgeA = 0; bridgeB = 0;
		
		FOR(i, 1, m) {
			u = channel[i].u;
			v = channel[i].v;
			if (!(u==parent[v] || v==parent[u])) continue;
			if (parent[u]==v) swap(u, v);
			if (low[v]>=number[v]) {
				if (channel[i].c==1) bridgeA++;
				else bridgeB++;
				channel[i].isBridge = true;
				
				long r1 = getRoot(u);
				long r2 = getRoot(v);
				if (r1!=r2)	dsu(u, v);
			}
		}
		
		FOR(i, bridgeA, n-1-bridgeB) {
			cost[i].first = a[i]+b[n-1-i];
			cost[i].second = i;
		}
		
		sort(cost+bridgeA, cost+(n-bridgeA-bridgeB), compare);
		
		sort(channel+1, channel+1+m, compareChannel);
		
		FOR(i, 1, m) {
			if (channel[i].isBridge) {
				cout << channel[i].pos << " ";	
				continue;
			}
			if (bridgeA>0 && channel[i].c==1) {
				long r1 = getRoot(channel[i].u);
				long r2 = getRoot(channel[i].v);
				if (r1!=r2) {
					dsu(r1, r2);
					cout << channel[i].pos << " ";
					bridgeA--;
				}
			}
			if (bridgeB>0 && channel[i].c==2) {
				long r1 = getRoot(channel[i].u);
				long r2 = getRoot(channel[i].v);
				if (r1!=r2) {
					dsu(r1, r2);
					cout << channel[i].pos << " ";
					bridgeB--;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
