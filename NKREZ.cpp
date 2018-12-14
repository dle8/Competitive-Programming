#include <iostream>
#define maxn 10000+10
using namespace std;
pair<int, int> yeucau[maxn];
int n;
int f[maxn];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

void swap(pair<int, int>&a,pair<int, int>&b) {
	pair<int, int> temp = a;
	a = b;
	b = temp;
}

void qsort(int dau, int cuoi) {//sort theo thoi diem ket thuc cua 1 yeu cau
	int i = dau;
	int j = cuoi;
	int mid = yeucau[(dau+cuoi)/2].second;
	
	do {
		while (yeucau[i].second < mid) i++;
		while (yeucau[j].second > mid) j--;
		if (i<=j) {
			swap(yeucau[i], yeucau[j]);
			i++;
			j--;
		}
	} while (i<=j);
	
	if (i<cuoi) qsort(i, cuoi);
	if (dau<j) qsort(dau, j);
}

int bs(int dau, int cuoi, int key) {
	int d = dau;
	int c = cuoi;
	int mid;
	while (d<=c) {
		mid = (d+c)/2;
		if (key>=yeucau[mid].second) d = mid+1;
		else c = mid-1;
	}
	return c;//thang cuoi cung <= thang key
}

int main() {
	int j;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> yeucau[i].first >> yeucau[i].second;
	qsort(1, n);
		
	f[0] = 0;
	f[1] = yeucau[1].second - yeucau[1].first;
	for (int i=2; i<=n; i++) 
	{
		j = bs(1, i-1, yeucau[i].first);
		f[i] = max(f[i-1], (yeucau[i].second - yeucau[i].first) + f[j]);
	}
	cout << f[n];
	return 0;
}
