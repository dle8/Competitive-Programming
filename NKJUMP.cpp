#include <bits/stdc++.h>
#define maxn 1000+10
#define maxc 1000000000
using namespace std;

bool check[maxn][maxn];
long f[maxn], a[maxn], n;

long max(long a, long b) {
	if (a>b) return a;
	else return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long neo, res;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++)
		memset(check[i], false, sizeof(check[i]));
	for (int i=1; i<=(n-2); i++) {
		neo = i+2;
		for (int j=i+1; j<=(n-1); j++) 
		for (int k=neo; k<=n; k++) {
			if(a[i]+a[j]<a[k]) break;
			neo=k;
			if (a[i]+a[j]==a[k]) {
				check[i][k] = true;
				check[j][k] = true;
			}
		}
	}
	
	memset(f, 0, sizeof(f));
	f[1] = 1;
	f[2] = 1;

	for (int u=3; u<=n; u++) {
		f[u]=1;
		for (int v=1; v<=(u-1); v++) 
		if (check[v][u]) f[u] = max(f[u], f[v]+1);
	}	
			
	res = -maxc;
	for (int i=1; i<=n; i++) res = max(res, f[i]);
	cout << res;
	
	return 0;
}
