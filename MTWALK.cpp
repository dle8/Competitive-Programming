#include <bits/stdc++.h>
#include <string>
#define maxn 100+10
#define maxh 110+10
using namespace std;

struct node {
	int chiso, next;
};

node graph[maxn*maxn];
int lab[maxn*maxn];
int head[maxh], a[maxn*maxn];
bool check[maxn*maxn];
int n, maxHeight, minHeight;

int min(int a, int b) {
	if (a<b) return a;
	return b;
}

int max(int a, int b) {
	if (a>b) return a;
	else return b;
}

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void join(int r1, int r2) {
	if (lab[r1]==lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1]= r2;
}

void tickCheck(int docao) {//chon tat ca cac o co h la docao
	int k, v;
	k = head[docao];
	while (k!=0) {
		v = graph[k].chiso;
		check[v] = true;
		k = graph[k].next;	
	}
}

void doJoin(int docao) {
	int k, v, r1, r2;
	k = head[docao];
	while (k!=0) {
		v = graph[k].chiso;
		r1 = getRoot(v);
		if (v>=(n+1) && check[v-n]) {
			r2 = getRoot(v-n);
			if (r1!=r2) join(r1, r2);
		}
		if (v<=(n*n-n) && check[v+n]) {
			r2 = getRoot(v+n);
			if (r1!=r2) join(r1, r2);
		}
		if (v%n!=1 && check[v-1]) {
			r2 = getRoot(v-1);
			if (r1!=r2) join(r1, r2);
		}
		if (v%n!=0 && check[v+1]) {
			r2 = getRoot(v+1);
			if (r1!=r2) join(r1, r2);
		}
		k = graph[k].next;
	}
}

void process() {
	int v, r1,  r2, k, t;
	int low = min(a[1], a[n*n]);
	int high = max(a[1], a[n*n]);
	for (int i=low; i<=high; i++) {
		tickCheck(i);//chon het nhung thang co do cao la i
	}
	
	for (int i=low; i<=high; i++) {
		doJoin(i);
	}
	
	for (int l= low; l>=minHeight; l--) {
		tickCheck(l);
		doJoin(l);
		for (int h = high; h<=maxHeight; h++) {
			tickCheck(h);
			doJoin(h);
			if (getRoot(1) == getRoot(n*n)) {
				cout << h-l;
				return;
			}
		}
	}	

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int h;
	int dem = 0;
	cin >> n;
	maxHeight = -1;
	minHeight = 111;
	memset(head, 0, sizeof(head));
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			cin >> h;
			maxHeight = max(h, maxHeight);
			minHeight = min(h, minHeight);
			lab[(i-1)*n+j] = -1;
			a[(i-1)*n+j] = h;
			dem++;
			graph[dem].chiso = (i-1)*n+j;
			graph[dem].next = head[h];
			head[h] = dem;
		}
	memset(check, false, sizeof(check));
	process();
	return 0;
}
