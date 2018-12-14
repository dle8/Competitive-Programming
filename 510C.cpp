#include <bits/stdc++.h>
#include <algorithm>
#define maxn 100000+10
using namespace std;

int a[maxn], b[maxn], c[maxn];

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
		while (c[i]<mid) i++;
		while (c[j]>mid) j--;
		if (i<=j) {
			swap(c[i], c[j]);
			i++;
			j--;
		}
	} while (i<=j);
	if (dau<j) quicksort(dau, j);
	if (i<cuoi) quicksort(i, cuoi);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int res = 0, n, m;
	long long sum = 0;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		c[i] = a[i]-b[i];
		sum+=b[i];
	}
	
	if (sum>m) cout << -1;
	else {
		sort(c+1, c+n+1);
		for (int i=1; i<=n; i++) {
			if (sum+c[i]<=m) {
				sum+=c[i];
				res++;
			}
			else break;
		}
		cout << n-res;
	}
	return 0;
}
