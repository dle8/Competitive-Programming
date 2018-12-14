#include <iostream>
#include <string.h>
#define maxn 300+10
using namespace std;

int n, dem;
int w[maxn], u[maxn*maxn], v[maxn*maxn], c[maxn*maxn], lab[maxn], mingieng[maxn];
bool read[maxn][maxn];
bool check[maxn];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

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
	x = lab[r1] + lab[r2];
	if (lab[r1] > lab[r2]) {//r1 has fewer nodes in its tree than r2
		lab[r1] = r2;
		lab[r2] = x;
		mingieng[r2] = min(mingieng[r1], mingieng[r2]);
	}
	else {
		lab[r1] = x;
		lab[r2] = r1;
		mingieng[r1] = min(mingieng[r1], mingieng[r2]);
	}
}

void kruskal() {
	int weight, r1, r2;
	
	memset(lab, -1, sizeof(lab));
	memset(check, false, sizeof(check));
	for (int i=1; i<=n; i++) mingieng[i] = w[i]; 
	
	for (int i=1; i<=dem; i++) {
		r1 = getRoot(u[i]);
		r2 = getRoot(v[i]);
		if (r1!=r2) 
			if (c[i] < max(mingieng[r1], mingieng[r2])) {
				check[i] = true;//chon canh c[i] tinh vao cay
				disjointSet(r1, r2);	
			}			
	}
	
	weight = 0;
	for (int i=1; i<=dem; i++) 
		if (check[i]) weight+=c[i];
		
	memset(check, false, sizeof(check));
	
	for (int i=1; i<=n; i++) {
		r1 = getRoot(i);
		if (!check[r1]) {//neu nhu goc r1 cua cay chua i chua dc tinh thi + mingieng[r1] vao weight
			weight+=mingieng[r1];
			check[r1] = true;
		}
	}
	
	cout << weight;
	
}

int main() {
	int input;
	cin >> n;
	memset(read, true, sizeof(read));

	for (int i=1; i<=n; i++) cin >> w[i];
	
	dem = 0;//dem max = n^2/2;
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (read[i][j] && read[j][i] && (i!=j)) {
				dem++;//if read(j,i) k can dem++ nua -> duyet cay khung nhanh hon
				u[dem] = i;
				v[dem] = j;
				cin >> c[dem];
				read[i][j] = false;
			}
			else cin >> input;
		}
		
	qsort(1,dem);
	kruskal();
	return 0;
}
