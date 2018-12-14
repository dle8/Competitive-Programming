#include <bits/stdc++.h>
#define maxn 1000+10
#define maxm 10000+10
using namespace std;

int n;
int lab[maxn], t[maxm], u[maxm], v[maxm];

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void qsort(int dau, int cuoi) {
	int i= dau;
	int j= cuoi;
	int mid = t[(dau+cuoi)/2];
	
	do {
		while (t[i]<mid) i++;
		while (t[j] >mid) j--;
		if (i<=j) {
			swap(t[i], t[j]);
			swap(u[i], u[j]);
			swap(v[i], v[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qsort(i, cuoi);
	if (dau<j) qsort(dau, j);
}

int getRoot(int u) {
	if (lab[u] >0) {
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
	
	if (lab[goc1]<lab[goc2]) lab[goc2] = goc1;
	else lab[goc1] = goc2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, max, r1, r2;
	cin >> n >> m;
	for (int i=1; i<=m; i++)
		cin >> u[i] >> v[i] >> t[i];
	qsort(1,m);
	for (int i=1; i<=n; i++) lab[i] = -1;
	max = -1000000000;
	for (int i=1; i<=m; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) {
			disjointSet(r1, r2);
			if (t[i]>max) max = t[i];
		}
	}
	
	cout << max;
	return 0;
}
