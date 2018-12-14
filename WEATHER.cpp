#include <bits/stdc++.h>
#define maxn 100+10
#define maxm 5000+10
using namespace std;

struct node {
	long v, next;
	bool way;
};

node graph[2*maxm];
long n, m, tcount, head[maxn], check[maxn], socon[maxn], low[maxn], number[maxn];

void dfs(long u) {
	long v;
	tcount++;
	number[u] = tcount;//tcount luu so thu tu cua thg u trong luc duyet dfs
	low[u] = n+1;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (graph[i].way) {
			if (graph[i+1].v==u) graph[i+1].way = false;//bo canh (v, u)
			else graph[i-1].way = false;
			if (check[v]==0) {//v chua dc di tham
				check[v] = u;
				dfs(v);
				low[u] = min(low[u], low[v]);
				socon[u]+=(socon[v]+1);
			}
			else low[u] = min(low[u], number[v]);
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, res, bridge;
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].way = true;
		graph[2*i].next = head[u];
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].way = true;
		graph[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	
	tcount = 0;
	memset(check, 0, sizeof(check));
	memset(socon, 0, sizeof(socon));
	for (int i=1; i<=n; i++) 
		if (check[i]==0) {
			check[i] = -1;
			dfs(i);	
		}
	
	res = 0;
	bridge++;
	for (int v=1; v<=n; v++) {
		u = check[v];
		if (u!=-1 && low[v]>=number[v]) res+=((socon[v]+1)*(n-socon[v]-1));
	}
	
	cout << res;
	return 0;
}
