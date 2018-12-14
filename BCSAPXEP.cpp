#include <iostream>
#define maxn 1000+10
using namespace std;

int n;
int a[maxn];

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void qsort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = a[(dau+cuoi)/2];
	
	do {
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
		if (i<=j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qsort(i, cuoi);
	if (dau < j) qsort(dau, j);
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	qsort(1, n);
	for (int i=1; i<=n; i++) cout << a[i] << endl;
	return 0;
}
