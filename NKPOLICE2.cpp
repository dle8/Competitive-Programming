#include <bits/stdc++.h>
#define maxn 100000+10
#define maxm 500000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long v, next;
};

node graph[2*maxm];
long number[maxn], low[maxn], parent[maxn], child[maxn], tplt[maxn], tcount, component, n, head[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	tcount++;
	number[u] = tcount;
	low[u] = n+1;
	tplt[u] = component;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (parent[v]==0) {
			parent[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], number[v]);
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long e, u, v, a, b, c, g1, g2, q, tcase;
	cin >> n >> e;
	FOR(i, 1, e) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}		
	
	tcount = 0;
	component = 0;
	FOR(i, 1, n) {
		if (parent[i]==0) {
			component++;
			parent[i] = -1;
			dfs(i);
		}
	}
	
	FOR(i, 1, n) {
		u = parent[i];
		if (u!=-1) child[u]++;
	}
	
	cin >> q;
	FOR(i, 1, q) {
		cin >> tcase;
		if (tcase==1) {
			cin >> a >> b >> g1 >> g2;
			if (tplt[a]!=tplt[g1] || tplt[a]!=tplt[g2]) {
				cout << "yes" << endl;
				continue;
			}
			if (parent[g1]==g2) swap(g1, g2);
			if (low[g2]>number[g1]) cout << "no" << endl;
			else cout << "yes" << endl;
		}
		else {
			cin >> a >> b >> c;
			if (tplt[a]!=tplt[c]) {
				cout << "yes" << endl;
				continue;
			}
			u = parent[c];
			if (low[c]>number[c] && (child[c]>=2 || u!=-1)) cout << "no" << endl;
			else cout << "yes" << endl;
		}
	}
	return 0;
}
