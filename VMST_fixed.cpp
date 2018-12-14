#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#define maxn 1000+10
#define maxm 1500+10
using namespace std;

struct node {
	int u, v, c, next;
};

int n, m;
bool check[maxn];
int lab[maxn], head[maxn];
node tree[2*maxm];

void dfs(int u) {
	int v;
	int i = head[u];
	check[u] = false;
	while (i!=0) {
		v = tree[i].v;
		if (check[v]) {
			tree[i].c=2;
			dfs(v);
		}
		i = tree[i].next;
	}
}

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, r1, r2;
	cin >> n >> m;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=m; i++) {
		cin >> u >> v;
		tree[2*i].u = u;
		tree[2*i].v = v;
		tree[2*i].c = 1;
		tree[2*i].next = head[u];
		head[u] = 2*i;
		
		tree[2*i+1].u = v;
		tree[2*i+1].v = u;
		tree[2*i+1].c = 1;
		tree[2*i+1].next = head[v];
		head[v] = 2*i+1;
		
	}
	cout << 3 << endl;
	memset(check, true, sizeof(check));
	dfs(1);
	for (int i=2;i<=(2*m+1);i++)
	if (tree[i].c==2) cout<<tree[i].u<<" "<<tree[i].v<<endl;
	
	for (int i=1; i<=n; i++) lab[i] = -1;
	
	for (int o=1;o<=2;o++)
	for (int i=2; i<=(2*m+1); i++) 
	if (tree[i].c==o){
		r1 = getRoot(tree[i].u);
		r2 = getRoot(tree[i].v);
		if (r1!=r2) {
			disjointSet(r1, r2);
			if (tree[i].c==2) tree[i].c = 4;
			else tree[i].c = 3;
		}
	}
	for (int i=2;i<=(2*m+1);i++)
	if (tree[i].c>2) cout<<tree[i].u<<" "<<tree[i].v<<endl;
	
	
	for (int i=1; i<=n; i++) lab[i] = -1;
	
	for (int o=1;o<=4;o++)
	for (int i=2; i<=(2*m+1); i++) 
	if (tree[i].c==o){
		r1 = getRoot(tree[i].u);
		r2 = getRoot(tree[i].v);
		if (r1!=r2) {
			disjointSet(r1, r2);
			cout<<tree[i].u<<" "<<tree[i].v<<endl;		
		}
	}	
	return 0;
}
