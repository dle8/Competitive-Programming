#include <bits/stdc++.h>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, r, l) for (int i=r; i>=l; i--)
#define maxn 30000+10
#define maxq 300000+10
using namespace std;

struct node {
	long v;
	node* next;
};

struct q {
	string tcase;
	string ans = "";
	long u, v;
};

q query[maxq];
long n, nChain, parent[maxn], chainHead[maxn], nchild[maxn], tcount, flatTree[maxn], chainOf[maxn], height[maxn], lab[maxn], tnext[maxn][20];
long it[4*maxn], pen[maxn];
node* head[maxn];

void swap(long&a, long&b) {
	long temp = a;
	a = b;
	b = temp;
}

long getRoot(long u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void dsu(long r1, long r2) {
	if (lab[r1]==lab[r2]) {
		lab[r2] = r1;
		lab[r1]--;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

void findHV(long u) {//dfs lan tim so con cua moi thang
	long v, child;
	node* p = head[u];
	node* firstChild = nullptr;
	node* heavyVertex = new node;
	heavyVertex->v = n+1;
	while (p!=nullptr) {
		v = p->v;
		if (parent[v]==0) {
			height[v] = height[u]+1;
			if (firstChild==nullptr) firstChild = p;
			parent[v] = u;
			findHV(v);
			nchild[u]+=(nchild[v]+1);
			if (nchild[v]>nchild[heavyVertex->v]) heavyVertex = p;
		}
		p = p->next;
	}
	
	if (heavyVertex->v!=(n+1)) swap(firstChild->v, heavyVertex->v);//nho dau thg head[u]->v k phai la con cua u
}

void dfs2(long u) {
	tcount++;
	flatTree[u] = tcount;
	chainOf[u] = nChain;
	long v;
	node* p = head[u];
	
	long numth = 0;
	while (p!=nullptr) {
		v = p->v;
		if (parent[v]==u) {
			numth++;
			if (numth>=2) chainHead[++nChain] = v;
			dfs2(v);
		}
		p = p->next;
	}
}

void constructTnext() {
	tnext[1][0] = 0;
	FORU(u, 2, n) tnext[u][0] = parent[u];
	
	FORU(i, 1, (int)(log(n)/log(2))) 
	FORU(u, 1, n)
		if (tnext[tnext[u][i-1]][i-1]!=0) tnext[u][i] = tnext[tnext[u][i-1]][i-1];
}

long lca(long u, long v) {
	if (height[v]>height[u]) swap(u, v);
	
	FORD(i, (int)(log(height[u]-height[v])), 0) 
		if (height[tnext[u][i]]>=height[v]) u = tnext[u][i];
		
	if (u==v) return u;
	
	FORD(i, (int)(log(height[u]-1)), 0) 
		if (tnext[u][i]!=tnext[v][i]) {
			u = tnext[u][i];
			v = tnext[v][i];
		}
		
	return parent[u];
}

void update(long cs, long u, long v, long i, long val) {
	if (i<u || v<i) return;
	it[cs]+=val;
	if (u==v) return;
	long mid = (u+v)/2;
	update(2*cs, u, mid, i, val);
	update(2*cs+1, mid+1, v, i, val);
}

long itSum(long cs, long u, long v, long l, long r) {
	if (r<u || v<l) return 0;
	if (l<=u && v<=r) return it[cs];
	long mid = (u+v)/2;
	return itSum(2*cs, u, mid, l, r) + itSum(2*cs+1, mid+1, v, l, r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long r1, r2, q;
	string tcase;
	node* p;
	cin >> n;
	FORU(i, 1, n) {
		lab[i] = -1;
		cin >> pen[i];
	}
	cin >> q;
	FORU(i, 1, q) {
		cin >> query[i].tcase >> query[i].u >> query[i].v;
		if (query[i].tcase=="bridge") {
			r1 = getRoot(query[i].u);
			r2 = getRoot(query[i].v);
			if (r1!=r2) {
				dsu(r1, r2);
				
				p = new node;
				p->v = query[i].v;
				p->next = head[query[i].u];
				head[query[i].u] = p;
				
				p = new node;
				p->v = query[i].u;
				p->next = head[query[i].v];
				head[query[i].v] = p;
				
				query[i].ans = "yes";
			}
			else query[i].ans = "no";
		}
		if (query[i].tcase=="excursion") {
			r1 = getRoot(query[i].u);
			r2 = getRoot(query[i].v);
			if (r1!=r2) query[i].ans = "impossible";
		}
	}
	
	height[1] = 1;
	parent[1] = -1;
	findHV(1);//dong thoi xay dung mang parent cho lca
	tcount = 0;
	nChain = 1;
	chainHead[1] = 1;
	dfs2(1);
	
	constructTnext();
	FORU(i, 1, n) update(1, 1, n, flatTree[i], pen[i]);
	
	FORU(i, 1, q) {
		if (query[i].tcase=="bridge") cout << query[i].ans << "\n";
		if (query[i].tcase=="penguins") {
			update(1, 1, n, flatTree[query[i].u], query[i].v-pen[i]);
			pen[i] = query[i].v;
		}
		if (query[i].tcase=="excursion") {
			if (query[i].ans=="impossible") cout << query[i].ans << "\n";
			else {
				long ancestor = lca(query[i].u, query[i].v);
				long u = query[i].u;
				long v = query[i].v;
				long dist = 0;
				while (chainOf[u]!=chainOf[ancestor] && u!=0) {
					dist+=itSum(1, 1, n, flatTree[u], flatTree[chainHead[chainOf[u]]]);
					u = parent[chainHead[chainOf[u]]];
				}
				
				while (chainOf[v]!=chainOf[ancestor] && v!=0) {
					dist+=itSum(1, 1, n, flatTree[v], flatTree[chainHead[chainOf[v]]]);
					v = parent[chainHead[chainOf[v]]];
				}
				
				dist+=((flatTree[u]<flatTree[v])?itSum(1, 1, n, flatTree[u], flatTree[v]):itSum(1, 1, n, flatTree[v], flatTree[u]));
				
				cout << dist << "\n";
			}
		}
	}
	
	return 0;
}
