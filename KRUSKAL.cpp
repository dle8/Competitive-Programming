#include <iostream>
#define maxn 15000+100

using namespace std;
int n, m;
int u[maxn], v[maxn], c[maxn], lab[maxn];

void swapVal(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void qsort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = c[rand() % (j-i + 1) + i];//random number from 0 to j-i + i -> rand num from i to j
	//phai luu mid bang gia tri c, chu k dc luu bang chi so
	//vi khi swap co the thang c[mid] da bi doi cho -> dan den c[mid] thay doi
	do {
		while (c[i] < mid) i++;
		while (c[j] > mid) j--;
		if (i<=j) {
			swapVal(u[i], u[j]);
			swapVal(v[i], v[j]);
			swapVal(c[i], c[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qsort(i, cuoi);
	if (dau<j) qsort(dau, j);
}

//viet ham getRoot bang de quy-> gan lab cua moi dinh trong cay la thang goc luon thay vi phai duyet qua moi thang cha
int getRoot(int u) {
	if (lab[u] > 0) {
		lab[u] = getRoot(lab[u]);
		return lab[u];	
	}
	return u;
}	

void disjointSet(int r1, int r2) {//union 2 cay co goc la r1, r2
	int x;
	x = lab[r1] + lab[r2];
	if (lab[r1] > lab[r2]) {//cay goc r1 co it dinh hon cay goc r2 -> chon cay goc r2 lam goc
		lab[r1] = r2;
		lab[r2] = x;
	}
	else {
		lab[r1] = x;
		lab[r2] = r1;
	}
}

int main() {
	int r1, r2, weight;
	cin >> n >> m;//n: so dinh, m: so canh cua do thi
	for (int i=1; i<=m; i++) 
		cin >> u[i] >> v[i] >> c[i];		
	
	qsort(1, m);
	
	for (int i=1; i<=n; i++) lab[i] = -1;//ban dau khoi tao moi cay trong do thi chi bao gom 1 dinh -> lab[i] = -so con = -1;
	
	weight = 0;
	
	for (int i=1; i<=m; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) {
			weight+=c[i];
			disjointSet(r1, r2);
		}
	}

	cout << weight;
	return 0;
}
