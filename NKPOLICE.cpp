#include <bits/stdc++.h>
#include <fstream>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
#define maxm 500000+10
#define maxn 100000+10
using namespace std;

struct node {
	long v, next;
	bool choose;
};

node graph[2*maxm];
long tcount, component, check[maxn], low[maxn], number[maxn], head[maxn], tplt[maxn], n, child[maxn];

void swap(long&a, long&b) {
	long temp = a;
	a = b;
	b = temp;
}

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
		if (!graph[i].choose) {
			if (graph[i+1].v==u) graph[i+1].choose = true;
			else graph[i-1].choose = true;
			if (check[v]==0) {
				check[v] = u;
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], number[v]);
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, e, q, tcase, a, b, g1, g2, c;
	
	cin >> n >> e;
	FORU(i, 1, e) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].choose = false;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].choose = false;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}

	tcount = 0;
	component = 0;	
	FORU(i, 1, n) {
		if (check[i]==0) {
			component++;
			check[i] = -1;
			dfs(i);
		}
	}
	
	FORU(i, 1, n) {
		u = check[i];
		if (u!=-1) child[u]++;
	}
	
	cin >> q;
	FORU(i, 1, q) {
		cin >> tcase;
		if (tcase==1) {
			cin >> a >> b >> g1 >> g2;
			if (tplt[g1]!=tplt[a]) cout << "yes" << endl;
			else {
				if (check[g1]==g2) swap(g1, g2);
				if (low[g2]>=number[g2]) cout << "no" << endl;
				else cout << "yes" << endl;
			}
		}
		else {
			cin >> a >> b >> c;
			if (tplt[c]!=tplt[a]) cout << "yes" << endl;
			else {
				u = check[c];
				if (low[c]>=number[c] && (child[c]>=2 || u!=-1)) cout << "no" << endl;
				else cout << "yes" << endl;	
			}			
		}
	}
	return 0;
}
