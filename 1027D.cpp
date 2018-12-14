#include <bits/stdc++.h>
#define maxn 200000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000
using namespace std;

struct node {
	long v, next;
};

node graph[maxn];
bool inGraph[maxn];
long a[maxn], c[maxn], head[maxn], n, component, tcount, number[maxn], low[maxn], check[maxn];
list<long> tplt[maxn];
list<long>::iterator it;
stack<long> Stack;

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	long i = head[u];
	tcount++;
	number[u] = tcount;
	low[u] = n+1;
	Stack.push(u);
	while (i!=0) {
		v = graph[i].v;
		if (inGraph[v]) {
			if (check[v]==0) {
				check[v] = u;
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], number[v]);
		}
		i = graph[i].next;
	}
	if (low[u]==number[u]) {
		component++;
		do {
			v= Stack.top();
			Stack.pop();
			tplt[component].push_back(v);
		} while (v!=u);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long cost;
	cin >> n;
	FOR(i, 1, n) cin >> c[i];
	FOR(i, 1, n) {
		cin >> a[i];
		graph[i].v = a[i];
		graph[i].next = head[i];
		head[i] = i;
	}
	
	memset(inGraph, true, sizeof(inGraph));
	component = 0;
	memset(check, 0, sizeof(check));	
	tcount = 0;
	FOR(i, 1, n) {
		if (check[i]==0) {
			check[i] = -1;
			dfs(i);
		}
	}
	
	cost = 0;
	FOR(i, 1, component){
		long minCost = oo;
		for(it=tplt[i].begin(); it!=tplt[i].end(); ++it)minCost = min(minCost, c[*it]);		
		cost+=minCost;		
	}
	
	cout << cost;
	
	return 0;
}
