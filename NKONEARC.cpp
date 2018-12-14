#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define maxm 30000+10
#define maxn 2000+10
using namespace std;

struct node {
	long u, v, next;
};

node graph[2*maxm];
long n, m, tcount, component, tplt[maxn], tpltNoOut, low[maxn], number[maxn], head[maxn], rhead[maxn];
stack<long> Stack;
list<long> mylist[maxn];
list<long>::iterator it, it2;
bool inGraph[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	tcount++;
	number[u] = tcount;
	low[u] = number[u];
	long i = head[u];
	Stack.push(u);
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
		component++;
		do {
			v = Stack.top();
			Stack.pop();
			inGraph[v] = false;
			tplt[v] = component;
			mylist[component].push_back(v);
		} while (v!=u);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool noIn, noOut;
	long u, v, tpltNoIn, tpltNoOut, noOutCount, noInCount;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		head[u] = 2*i;

		graph[2*i+1].v = u;
		graph[2*i+1].next = rhead[v];
		rhead[v] = 2*i+1;		
	}
	
	memset(inGraph, true, sizeof(inGraph));
	tcount = 0;
	component = 0;
	FOR(i, 1, n) if (number[i]==0) dfs(i);
	
	noOutCount = 0;
	noInCount = 0;
	tpltNoOut = -1;
	tpltNoIn = -2;
	
	//dem so thanh tplt manh k co loi ra-> neu nhu >=2 cout << no, neu ==1 thi ktra xem no co duong di tu thg khac vao hay k-> co thi yes
	FOR(i, 1, component) {
		noOut = true;
		noIn = true;
		for (it=mylist[i].begin(); it!=mylist[i].end(); ++it) {
			long j = head[*it];
			while (j!=0) {
				v = graph[j].v;
				if (tplt[v]!=i) noOut = false;
				j = graph[j].next;
			}
			
			j = rhead[*it];
			while (j!=0) {
				v = graph[j].v;
				if (tplt[v]!=i) noIn = false;
				j = graph[j].next;
			}
		}
		if (noOut) {
			noOutCount++;
			tpltNoOut = i;
		}
		if (noIn) {
			noInCount++;
			tpltNoIn = i;
		}
	}
	if (noOutCount>=2 || noInCount>=2) return cout << "NO", 0;
	if (tpltNoOut==tpltNoIn) return cout << "NO", 0;
	
	cout << "YES" << "\n";
	for (it=mylist[tpltNoIn].begin(); it!=mylist[tpltNoIn].end(); ++it) 
	for (it2=mylist[tpltNoOut].begin(); it2!=mylist[tpltNoOut].end(); ++it2)
	return cout << *it2 << " " << *it, 0;
	
	return 0;
}
