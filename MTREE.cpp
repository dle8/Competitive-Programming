#include <bits/stdc++.h>
#define maxn 100000+10
#define k 1000000007
using namespace std;

struct node {
	long long v, c, next;
};

long n;
node graph[2*maxn];
int check[maxn], head[maxn];
long long sumTo[maxn], tree[maxn];

void dfs(int u) {
	long long v, weightCha, weightCayCon;
	int i = head[u];
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==0) {
			check[v]=u;
			dfs(v);
			sumTo[u] = (sumTo[u]+((sumTo[v]+1)%k*graph[i].c)%k)%k;
		}
		i = graph[i].next;
	}
	
	i = head[u];
	weightCha = sumTo[u];
	
	tree[u] = sumTo[u];
	
	while (i!=0) {
		v = graph[i].v;
		if (check[v]==u) {
			tree[u] = (tree[u]+tree[v])%k;
			weightCayCon = (((sumTo[v]+1)%k)*graph[i].c)%k;
			tree[u]=(tree[u] + (weightCayCon*(weightCha-weightCayCon+k)%k)%k)%k;
			weightCha=(weightCha-weightCayCon+k)%k;
		}
		i = graph[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dem, u, v, w;
	dem = 0;
	cin >> n;
	memset(tree, 0, sizeof(tree));
	memset(sumTo, 0, sizeof(sumTo));
	memset(check, 0, sizeof(check));
	for (int i=1; i<=(n-1); i++) {
		cin >> u >> v>> w;
		dem++;
		graph[dem].v = v;
		graph[dem].c = w;
		graph[dem].next = head[u];
		head[u] = dem;
		
		dem++;
		graph[dem].v = u;
		graph[dem].c = w;
		graph[dem].next = head[v];
		head[v] = dem;
	}
	memset(check, 0, sizeof(check));
	check[1] = -1;
	dfs(1);
//	for (int i=1;  i<=n; i++) 
//		cout << i << " " << sumTo[i] << "\n";
	cout << tree[1]%k; 
	return 0;
}
