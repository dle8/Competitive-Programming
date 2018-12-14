#include <bits/stdc++.h>
#define maxn 1000+10
#define maxm 10000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000
using namespace std;

typedef struct node {
	long v;
	node* next;
};

long n, m, id, parent[maxn], num[maxn], q[maxn], maxLength, f[maxn], trace[maxn];
node* head[maxn];
list<long> mylist;

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

void dfs(long u) {
	node* p = head[u];
	while (p!=nullptr) {
		if (parent[p->v]==0) {
			parent[p->v] = u;
			dfs(p->v);
		}
		p = p->next;
	}
	num[u] = id;
	q[id] = u;
	id--;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, s;
	cin >> n >> m;
	node* p = nullptr;
	FOR(i, 1, m) {
		cin >> u >> v;
		p = new node;
		p->v = v;
		p->next = head[u];
		head[u] = p;
		
		p = new node;
		p->v = u;
		p->next = head[v];
		head[v] = p;
	}
	
	id = n;
	FOR(i, 1, n)
	if (parent[i]==0) {
		parent[i] = -1;
		dfs(i);
	}
	
	FOR(i, 1, n) cout << i << " " << num[i] << "\n";
	FOR(i, 1, n) f[i] = -oo;
	f[q[1]] = 1;
	FOR(i, 1, n) {
		u = q[i];
		p = head[u];
		bool isRoot = true;
		while (p!=nullptr) {
			if (num[p->v]<num[u]) {
				isRoot = false;
				if (f[u]<f[p->v]+1) {
					f[u] = f[p->v]+1;
					trace[u] = p->v;
				}
			} 
			p = p->next;
		}
		if (isRoot) f[u] = 1;
	}
	delete p;
	
	maxLength = -oo;
	FOR(i, 1, n) 
	if (f[i]>maxLength) {
		maxLength = f[i];
		s = i;
	}
	
	cout << maxLength << "\n";
	do {
		mylist.push_back(s);
		s = trace[s];
	} while (s!=0);
	for (list<long>::iterator it=mylist.end(); it!=mylist.begin(); --it) cout << *it << " ";
	return 0;
}
