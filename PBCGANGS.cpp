#include <bits/stdc++.h>
#define maxn 1000+10
#define maxm 5000+10
using namespace std;

int n;
bool check[maxn];
int pF[maxm], qF[maxm], pE[maxm], qE[maxm], lab[maxn];

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	if (lab[r1]==lab[r2]) {//if cay con goc r1 bang cay con goc r2
		lab[r1]--;
		lab[r2] = r1;
		return;
	}
	if (lab[r1]<lab[r2]) lab[r2] = r1;
	else lab[r1] = r2;
}

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(int p[], int q[], int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = p[(dau+cuoi)/2];
	
	do {
		while (p[i]<mid) i++;
		while (p[j]>mid) j--;
		if (i<=j) {
			swap(p[i], p[j]);
			swap(q[i], q[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) quicksort(p, q, i, cuoi);
	if (dau<j) quicksort(p, q, dau, j);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, r1, r2, demE, demF, res, p, q;
	char c;
	demE = 0;
	demF = 0;
	cin >> n;
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> c >> p >> q;
		if (p>q) swap(p, q);
		if (c=='F') {
			demF++;
			pF[demF] = p;
			qF[demF] = q;
		}
		
		if (c=='E') {
			demE++;
			pE[demE] = p;
			qE[demE] = q;
		}
	}
	
	for (int i=1; i<=n; i++) lab[i] = -1;
	
	for (int i=1; i<=demF; i++) {
		r1 = getRoot(pF[i]);
		r2 = getRoot(qF[i]);
		if (r1!=r2) disjointSet(r1, r2);
	}
	quicksort(pE, qE, 1, demE);
	for (int i=1; i<=(demE-1); i++) {
		r1 = getRoot(qE[i]);
		r2 = getRoot(qE[i+1]);
		if (pE[i]==pE[i+1] && r1!=r2) disjointSet(r1, r2);
	}
	quicksort(qE, pE, 1, demE);
	for (int i=1; i<=(demE-1); i++) {
		r1 = getRoot(pE[i]);
		r2 = getRoot(pE[i+1]);
		if (qE[i]==qE[i+1] && r1!=r2) disjointSet(r1, r2);
	}
	memset(check, true, sizeof(check));
	res = 0;
	for (int i=1; i<=n; i++) {
		r1 = getRoot(i);
		if (check[r1]) {
			res++;
			check[r1] = false;
		}
	}
	cout << res;
	return 0;
}
