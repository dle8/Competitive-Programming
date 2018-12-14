#include <bits/stdc++.h>
#define maxq 300000+10
#define maxn 30000+10
using namespace std;

struct node {
	int v, next;
};

struct ques{
	string type;
	int u, v, ancestor;
	string ans;
};

int n;
node graph[2*maxq];
bool check[maxn];
int tnext[maxn][15], lab[maxn], height[maxn], parent[maxn], si[maxn], ei[maxn], head[maxn], it[8*maxn], pen[maxn];
ques query[maxq]; 


int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (lab[r1] == lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

void dfs(int u, int&dem) {
	int v;
	int i = head[u];
	check[u] = false;
	dem++;
	si[u] = dem;
	while (i!=0) {
		v = graph[i].v;
		if (check[v]) {
			height[v] = height[u] + 1;
			parent[v] = u;
			dfs(v, dem);
		}
		i = graph[i].next;
	}
	dem++;
	ei[u] = dem;
}

void update(int cs, int u, int v, int i, int val) {
	if (i<u || v<i) return;
	it[cs]+=val;
	if (u==v) return;
	int mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

int getSum(int cs, int u, int v, int l, int r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	int mid = (u+v)/2;
	return(getSum(2*cs, u, mid, l, r)+getSum(2*cs+1, mid+1, v, l, r));
}

void init() {
	for (int u=1; u<=n; u++) tnext[u][0] = parent[u];
	
	for (int i=1; i<=int(log(n)/log(2)); i++) {//log(n+1)?
		for (int u=1; u<=n; u++) {
			if (tnext[tnext[u][i-1]][i-1]!=0) // chua vuot qua goc 0**
				tnext[u][i] = tnext[tnext[u][i-1]][i-1];//**
		}
	}
}

int lca(int u, int v) {
	int temp;
	if (height[u]<height[v]) {
		temp = u;
		u = v;
		v = temp;
	}
	
	for (int i=int(log(height[u]-height[v])/log(2)); i>=0; i--) {
		if (height[tnext[u][i]]>=height[v])
			u = tnext[u][i];
	}
	
	if (u==v) return u;
	
	for (int i=int(log(height[u]-1)/log(2)); i>=0; i--) {
		if (tnext[u][i]!=tnext[v][i]) {
			u = tnext[u][i];
			v = tnext[v][i];
		}
	}
	
	return parent[u];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q, r1, r2, dem, ancestor, u, v;
	string tcase;
	dem = 0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >>pen[i];
		lab[i] = -1;//khoi tao cha cua moi thang la chinh no va thg cha cua cha <0	
	}
	cin >> q;
	for (int i=1; i<=q; i++) {
		cin >> tcase;
		cin >> u >> v;
		query[i].type = tcase;
		query[i].u = u;
		query[i].v = v;
		if (tcase=="bridge") {
			r1 = getRoot(u);
			r2 = getRoot(v);
			if (r1!=r2) {
				disjointSet(r1, r2);
				dem++;
				graph[dem].v = v;
				graph[dem].next = head[u];
				head[u] = dem;
				
				dem++;
				graph[dem].v = u;
				graph[dem].next = head[v];
				head[v] = dem;
				
				query[i].ans = "yes";
			}
			else query[i].ans = "no";
		}
		if (tcase == "excursion") {
			r1 = getRoot(u);
			r2 = getRoot(v);
			if (r1!=r2) query[i].ans = "impossible";
		}
 	}
 	
 	memset(check, true, sizeof(check));
 	for (int i=1; i<=n; i++) {//tao 1 dinh ao 0. noi dinh ao nay voi nhung thang root cua cac cay
 		r1 = getRoot(i);
 		if (check[r1]) {
 			dem++;
 			graph[dem].v = r1;
 			graph[dem].next = head[0];
 			head[0] = dem;
 			check[r1] = false;
		}
	}
	
	memset(check, true, sizeof(check));
	dem = -1;
	height[0] = 0;
	dfs(0, dem);//dfs de lau chu trinh euler, vua tim lca, cap nhat mang height

	for (int i=0; i<=n; i++) {//for tu 0 hay 1?
		update(1, 1, 2*n, si[i], pen[i]);
		update(1, 1, 2*n, ei[i], -pen[i]);
	}
	
	init();

 	for (int i=1; i<=q; i++) {
 		if (query[i].type == "bridge") cout << query[i].ans << "\n";
 		if (query[i].type == "penguins") {
 			pen[query[i].u] = query[i].v;
 			update(1, 1, 2*n, si[query[i].u], query[i].v);
 			update(1, 1, 2*n, ei[query[i].u], -query[i].v);
		}
		if (query[i].type == "excursion") {
			if (query[i].ans == "impossible") cout << query[i].ans << "\n";
			else {
				ancestor = lca(query[i].u, query[i].v);
				int d1 = getSum(1, 1, 2*n, 1, ei[query[i].u]);
				int d2 = getSum(1, 1, 2*n, 1, ei[query[i].v]);
				int d3 = getSum(1, 1, 2*n, 1, ei[ancestor]);
				cout << d1+d2-2*d3+pen[ancestor] << "\n";	
			}
		}
	}
 	
	return 0;
}
