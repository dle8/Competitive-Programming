#include <bits/stdc++.h>
#include <string.h>
#define maxn 300+10
using namespace std;

int n, dem;
int u[maxn*maxn], v[maxn*maxn], c[maxn*maxn], lab[maxn];

void swapVal(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void qsort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = c[(dau+cuoi)/2];
	
	do {
		while (c[i] < mid) i++;
		while (c[j] > mid) j--;
		if (i<=j) {
			swapVal(c[i], c[j]);
			swapVal(u[i], u[j]);
			swapVal(v[i], v[j]);
			i++;//vi doi ca nhung thang bang mid nen neu k i++ va j-- thi lap vo han
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qsort(i, cuoi);
	if (dau < j) qsort(dau, j);
}

int getRoot(int u) {
	if (lab[u]>0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];
	}
	return u;
}

void disjointSet(int r1, int r2) {
	int x;
	if (lab[r1] == lab[r2]) {
		lab[r1]--;
		lab[r2] = r1;
	}
	else {
		if (lab[r1] > lab[r2]) lab[r1] = r2;
		else lab[r2] = r1;
	}
}

void kruskal() {
	int r1, r2;
	long weight;
	memset(lab, -1, sizeof(lab));
	
	weight = 0;
	for (int i=1; i<=dem; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) {
			weight+=c[i];
			disjointSet(r1, r2);
		}
	}
	
	cout << weight;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int input;
	cin >> n;
	dem = 0;
	//tao them 1 dinh n+1 voi w_i chinh la cost quang duong tu i den n+1.
	//bai toan tro ve tim cay khung voi trong so min cua n+1 dinh
	for (int i=1; i<=n; i++){
		dem++;
		u[dem] = n+1;
		v[dem] = i;
		cin >> c[dem];
	} 
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (j>i) {//if (i<=j) thi da doc roi -> k can doc them c[i,j]
				dem++;
				u[dem] = i;
				v[dem] = j;
				cin >> c[dem];
			}
			else cin >> input;
		}
		
	qsort(1,dem);
	kruskal();
	return 0;
}
