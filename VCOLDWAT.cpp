#include <bits/stdc++.h>
#include <math.h>
#define maxn 100000+10
using namespace std;

int n;

struct node {
	int v, next;
};

node tree[2*maxn];
int head[maxn], h[maxn];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

void dfs(int u) {
	int v;
	int i = head[u];
	while (i!=0) {
		v = tree[i].v;
		h[v] = h[u]+1;
		dfs(v);
		i = tree[i].next;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, dem, ong, nhanh1, nhanh2;
	cin >> n >> c;
	dem = 0;
	for (int i=1; i<=c; i++) {
		cin >> ong >> nhanh1 >> nhanh2;
		++dem;	
		tree[dem].v = nhanh1;
		tree[dem].next = head[ong];
		head[ong] = dem;
		
		++dem;
		tree[dem].v = nhanh2;
		tree[dem].next = head[ong];
		head[ong] = dem;
	} 
	memset(h, 0, sizeof(h));
	h[1]= 1;
	dfs(1);
	for (int i=1; i<=n; i++) cout << h[i] << endl;
	return 0;
}
