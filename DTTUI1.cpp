#include <iostream>
#define maxn 40+10
using namespace std;
long long w[maxn], v[maxn];
long long f[maxn][1000000000];
long long n, m;

long long max(long long a, long long b) {
	if (a>=b) return a;
	else return b;
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> w[i] >> v[i];
	//f[i,j] la gtri lon nhat co the co chon trong cac cuc vang tu 1->i voi tai trong toi da j
	for (int j=0; j<=m; j++) f[0][j] = 0;
	//neu chon cuc vang i thi f[i,j] = w[i] + f[i][j-w[i]] voi dieu kien j>=w[i]
			//neu k chon cuc vang i thi f[i,j] = f[i-1][j] -> lay max 2 gia tri
			
	for (int i=1; i<=n; i++)
		for (int j=0; j<=m; j++) {
			if (j>=w[i]) 
				f[i][j] = max(f[i-1][j], v[i] + f[i-1][j-w[i]]);
			else f[i][j] = f[i-1][j];	
		}
	
	//truy vet: neu f[n][m] = f[n-1][m] -> k chon goi thu m va nguoc lai
	
	cout << f[n][m];
	return 0;
}
