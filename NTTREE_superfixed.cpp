#include <bits/stdc++.h>
#include <string.h>
#define maxn 10000+10
using namespace std;

struct node {
	int v, next;
	long long c;
};

int n;
long long result;
long long sumToU[maxn];
int socon[maxn], head[maxn];
node tree[2*maxn];
int check[maxn];

void dfs(int u) {
	int v;
	int i = head[u];
	while (i!=0) {
		v = tree[i].v;
		if (check[v]==0) {//dat dieu kien de dam bao rang neu v la con cua u thi moi cong vao
			check[v]=u;
			dfs(v);	
			socon[u]+=socon[v]+1;
			sumToU[u]+=sumToU[v]+tree[i].c*(socon[v]+1);
		}
		i = tree[i].next;
	}
	
	result+=sumToU[u];
	
	i = head[u];
	while (i!=0){
		v = tree[i].v;
		if (check[v]==u) result+=(sumToU[v]+tree[i].c*(socon[v]+1))*(socon[u]-socon[v]-1);
		i = tree[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v;
	long long w;
	cin >> n;
	for (int i=1; i<=(n-1); i++) {
		cin >> u >> v >> w;
		u++;
		v++;
		tree[2*i].v = v;
		tree[2*i].c = w;
		tree[2*i].next = head[u];
		head[u] = 2*i; 
		
		tree[2*i+1].v = u;
		tree[2*i+1].c = w;
		tree[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	result = 0;
	check[1]=-1;
	dfs(1);
	cout<<result;
	return 0;
}
