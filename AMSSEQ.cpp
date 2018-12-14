#include <iostream>

using namespace std;

int a[10001];
int f[10001];

int max(int a, int b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	int n, k;
	cin >> n >>k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		f[i] = -1000000000;
	}

	f[0] = 0;
	for (int i=1; i<=n ; i++) 
		for (int j=1; j<=k; j++){
			if (j==1) f[i] = f[i-j] + a[i];
			else if (i-j>=0) f[i] = max (f[i], f[i-j] + a[i]);
		}
		 
	int max = -1000000000;
	for (int i=0; i<=n; i++) {//phai xet tu 0 vi no co the dung yen??
		if (f[i] > max) max = f[i];
	}
	
	cout << max;
}
