#include <iostream>
#include <string.h>
#define maxn 10000+10
#define maxm 50000+10
using namespace std;

struct node  {
	long v, next;
	bool way;
};

node graph[2*maxm];
long n, m, tcount, number[maxn], low[maxn], head[maxn], check[maxn], nchild[maxn];
bool iscut[maxn];

long min(long a, long b) {
	if (a<=b) return a;
	else return b;
}

void dfs(long u) {
	long v, temp;
	tcount++;
	number[u] = tcount;
	low[u] = n+1;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (graph[i].way) {
			if (graph[i+1].v == u) graph[i+1].way = false;
			else graph[i-1].way =  false;
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
	long bridge, cut, u, v;
	cin >> n >> m;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		graph[2*i].v = v;
		graph[2*i].next = head[u];
		graph[2*i].way = true;
		head[u] = 2*i;
		
		graph[2*i+1].v = u;
		graph[2*i+1].next = head[v];
		graph[2*i+1].way = true;
		head[v] = 2*i+1;
	}
	
	memset(check, 0, sizeof(check));
	tcount = 0;
	for (int i=1; i<=n; i++) 
		if (check[i]==0) {
			check[i] = -1;//danh dau day la goc cua 1 lan dfs
			dfs(i);
		}
		
	memset(nchild, 0, sizeof(nchild));
	for (int v=1; v<=n; v++) {
		u = check[v];
		if  (u!=-1) nchild[u]++;
	} 	
	
	bridge = 0;
	for (int v=1; v<=n; v++) {
		u = check[v];
		if (u!=-1 && low[v]>=number[v]) bridge++;
	}

	cut = 0;
	memset(iscut, false, sizeof(iscut));	
	for (int v=1; v<=n; v++) {
		u = check[v];
		if (u!=-1 && low[v]>=number[u] &&!iscut[u]) 
			if (check[u]!=-1 || nchild[u]>=2) {
				iscut[u] = true;
				cut++;
			}
	}
		
	cout << cut << " " << bridge;
	return 0;
}
