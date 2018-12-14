#include <bits/stdc++.h>
#define maxn 800+10
#define maxm 1000000+10
using namespace std;

struct node {
	long v, next;
};

node graph[maxm];
long tcount, n, component, number[maxn], low[maxn], head[maxn], rhead[maxn],tplt[maxn];
stack<long> Stack;
bool tpltNoIn[maxn], inGraph[maxn];

long min(long a, long b) {
	if (a<b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	tcount++;
	number[u] = tcount;
	low[u] = number[u];//vi chinh dinh u da la 1 tplt manh
	Stack.push(u);
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (inGraph[v]) {
			if (number[v]==0) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], number[v]);	
		}
		i = graph[i].next;
	}
	
	if (low[u]==number[u]) {
		long temp;
		component++;
		do {
			temp = Stack.top();
			tplt[temp] = component;
			inGraph[temp] = false;
			Stack.pop();
		} while (temp!=u);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, m, temp, res;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = rhead[v];
		rhead[v] = 2*i+1;
	}
	
	component = 0;
	tcount = 0;
	memset(inGraph, true, sizeof(inGraph));
	for (int i=1; i<=n; i++) 
		if (number[i]==0) dfs(i);
		
	memset(tpltNoIn, true, sizeof(tpltNoIn));
	for (int i=1; i<=n; i++) {
		temp = rhead[i];
		while (temp!=0) {
			u = graph[temp].v;
			if (tplt[u]!=tplt[i]) {//co duong noi tu 1 tplt khac vao tplt chua i tai nut i
				tpltNoIn[tplt[i]] = false;
				break;
			}
			temp = graph[temp].next;
		}
	}
	res = 0;
	for (int i=1; i<=component; i++) if (tpltNoIn[i]) res++;
	cout << res;
	return 0;
}
