#include <iostream>
#include <list>

using namespace std;

int a[1000];
int f[1000][50];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	
	for (int j=0; j<k; j++) {
		f[0][j] = -n;
	}
	
	f[0][0] = 0;
	f[0][a[0]%k] = 1;//
	
	for (int i=1; i<n; i++) {
		for (int j=0; j<k; j++) {
			if (f[i-1][j] >= f[i-1][(j-a[i]%k+k)%k]+1) f[i][j] = f[i-1][j];//
			else f[i][j] = f[i-1][(j-a[i]%k+k)%k]+1;//
		}
	}
		
	cout << f[n-1][0];
	return 0;
}
