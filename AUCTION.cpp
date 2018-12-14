#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;
int n;
int p[maxn];

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

int min(int a, int b) {
	if (a>=b) return b;
	else return a;
}

void quicksort(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	int mid = p[(dau+cuoi)/2];
	
	do {
		while (p[i]>mid) i++;
		while (p[j]<mid) j--;
		if (i<=j) {
			swap(p[i], p[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) quicksort(i, cuoi);
	if (dau<j) quicksort(dau, j);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int max, m, price;
	cin >> n >> m;
	for (int i=1; i<=m; i++) cin >> p[i];
	quicksort(1, m);
	max = -1000000000;
	for (int i=1; i<=min(m,n); i++) 
		if (p[i]*i>max) {
			price =  p[i];
			max = p[i]*i;	
		}
	cout << price << " " << max;
	return 0;
}
