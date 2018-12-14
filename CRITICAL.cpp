#include <bits/stdc++.h>
#define maxn 20000+10
#define maxm 200000+10
using namespace std;

struct node {
	long v, next;
	bool way;//danh dau chon chieu nao trong luc dinh chieu do thi
};

node graph[2*maxm];
long n, component, tcount, sodinh[maxn], nchild[maxn], label[maxn], number[maxn], low[maxn], head[maxn], check[maxn], socon[maxn];
bool iscut[maxn];

void dfs(long u) {
	long v;
	label[u] = component;//mang danh dau i thuoc thanh phan lien thong thu bao nhieu
	sodinh[component]++;//tang so dinh thuoc tlpt thu component them 1
	tcount++;//dung de dinh chieu do thi
	number[u] = tcount;
	low[u] = n+1;
	long i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (graph[i].way) {//tuc la chieu (u,v) chua bi bo di trong do thi
			if (graph[i+1].v==u) graph[i+1].way = false;//bo chieu (v,u)
			else graph[i-1].way = false;
			if (check[v]==0) {//tuc la v chua tham
				check[v] = u;
				dfs(v);
				socon[u]+=(socon[v]+1);
				if (low[u]>low[v]) low[u] = low[v];
			}
			else if (low[u]>number[v]) low[u] = number[v];
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, tplt, m, res, temp, con;
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
	
	memset(check, 0, sizeof(check));
	memset(sodinh, 0, sizeof(sodinh));
	component = 0;
	tcount = 0;
	for (int i=1; i<=n; i++) {
		if (check[i]==0) {
			check[i] = -1;//danh dau i la dinh cua cay dfs
			component++;
			dfs(i);
		}
	}
	
	memset(nchild, 0, sizeof(nchild));
	for (int v=1; v<=n; v++) {
		u = check[v];
		if (u!=-1) nchild[u]++;
	}
	
	res = 0;
	memset(iscut, false, sizeof(iscut));
	for (int v=1; v<=n; v++) {
		u = check[v];
		if (u!=-1 && low[v]>=number[u] && !iscut[u] && (check[u]!=-1 || nchild[u]>=2)) {
			iscut[u] = true;
			tplt = label[u];
			res+=((sodinh[tplt]-socon[u]-1)*socon[u]);
			
			temp = socon[u];
			int i = head[u];
			while (i!=0) {
				con = graph[i].v;
				if (check[con]==u) {
					res+=(socon[con]+1)*(temp-socon[con]-1);
					temp-=(socon[con]+1);
				}
				i = graph[i].next;
			}
		}
	}
	
	printf("%.2lf", res/double(n));
	return 0;
}
