#include <bits/stdc++.h>
#define maxm 100000+10
#define maxn 10000+10
using namespace std;

int n;
bool check[maxm];
int u[maxm], v[maxm], c[maxm];
int lab[maxn];

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = c[(dau+cuoi)/2];
	
	do {
		while (c[i] > mid) i++;
		while (c[j] < mid) j--;
		if (i<=j) {
			swap(u[i], u[j]);
			swap(v[i], v[j]);
			swap(c[i], c[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) quicksort(i, cuoi);
	if (dau<j) quicksort(dau, j);
}

int getRoot(int u) {
	if (lab[u] > 0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int goc1, int goc2) {
	if (lab[goc1] == lab[goc2]) {
		lab[goc1]--;
		lab[goc2] = goc1;
		return;
	}
	
	if (lab[goc1] < lab[goc2]) lab[goc2] = goc1;
	else lab[goc1] = goc2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, r1, r2, camera;
	cin >> n >> m;
	for (int i=1; i<=m; i++) cin >> u[i] >> v[i] >> c[i];
	quicksort(1, m);
	memset(check, true, sizeof(check));
	for (int i=1; i<=n; i++) lab[i] = -1;
	for (int i=1; i<=m; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) {
			disjointSet(r1, r2);
			check[i] = false;
		}
	}
	
	camera = 0;
	for (int i=1; i<=m; i++) 
		if (check[i]) camera+=c[i];
	cout << camera;
	return 0;
}
