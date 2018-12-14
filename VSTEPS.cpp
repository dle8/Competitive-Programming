#include <bits/stdc++.h>
#define maxn 100000+10
#define mod 14062008
using namespace std;

long n, k;
bool check[maxn];
long long f[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long brokenStair;
	cin >> n >> k;
	memset(check, true, sizeof(check));
	for (int i=1; i<=k; i++) {
		cin >> brokenStair;
		check[brokenStair] = false;
	}
	
	f[0] = 0;
	f[1] = 1;
	
	for (int i=2; i<=n; i++) {
		if (check[i]) f[i] = (f[i-1]+f[i-2])%mod;
		else f[i] = 0;
	}
	
	cout << f[n];
	
	return 0;
}
