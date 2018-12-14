#include <bits/stdc++.h>
#define maxn 400000+10
using namespace std;

int n;
long long result;
int a[2*maxn], b[2*maxn], c[2*maxn];

void swap(int &a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

void quicksort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = c[(dau+cuoi)/2];
	
	do {
		while (c[i]<mid) i++;
		while (c[j]>mid) j--;
		if (i<=j) {
			swap(c[i], c[j]);
			i++;
			j--;
		}
	} while(i<=j);
	
	if (i<cuoi) quicksort(i, cuoi);
	if (dau<j) quicksort(dau, j);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	result = 0;
	for (int i=1; i<=(2*n); i++) cin >> a[i] >> b[i];
	for (int i=1; i<=(2*n); i++) result+=b[i];
	
	for (int i=1; i<=(2*n); i++) c[i] = a[i]-b[i];
	quicksort(1, (2*n));
	for (int i=1; i<=n; i++) result+=c[i];
	cout << result;
	return 0;
}
