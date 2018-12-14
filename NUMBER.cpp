#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 10000+10
#define pb push_back
using namespace std;

long n, m, t, lab[maxn];
bool check[maxn];

struct node {
	long v;
	node* next;
};

node* head[maxn];
stack<long> Stack;
list<long> connected[maxn];
long num[maxn], low[maxn], tcount, component, numth[maxn], deg[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void dfs(long u) {
	long v;
	num[u] = low[u] = ++tcount;
	check[u] = false;
	node* p = head[u];
	Stack.push(u);
	while (p!=nullptr) {
		v = p->v;
		if (check[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
		p = p->next;
	}
	if (num[u]==low[u]) {
		++component;
		while (Stack.top()!=u) {
			connected[component].pb(Stack.top());
			numth[Stack.top()] = component;
			Stack.pop();
		}
		connected[component].pb(u);
		numth[u] = component;
		Stack.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long u, v, res;
	node* p;
	cin >> n >> m >> t;
	FOR(i, 1, m) {
		cin >> u >> v;
		p = new node;
		p->v = v;
		p->next = head[u];
		head[u] = p;                                                                                     
	}
	
	component = 0;
	tcount = 0;
	
	memset(check, true, sizeof(check));
	FOR(i, 1, n) {
		if (check[i]) dfs(i);
	}
	
	res = 0;
	FOR(i, 1, component) {
		if (numth[t]==i) continue;
		for (auto iter = connected[i].begin(); iter!=connected[i].end(); iter++) {
			p = head[*iter];
			while (p!=nullptr) {
				v = p->v;
				if (numth[v]!=numth[*iter]) deg[i]++;
				p = p->next;
			}
		}
		if (deg[i]==0) res++; 
	}

	cout << res;	
	return 0;
}
