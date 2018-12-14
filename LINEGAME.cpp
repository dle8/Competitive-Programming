#include <bits/stdc++.h>
#define maxn 1000000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000000000000
using namespace std;

long n, a[maxn];
long long res, f[maxn][3], maxd[3];

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	//maxd[1] la tong lon nhat nhan duoc voi thg cuoi cung la -1 thg nao do
	//maxd[2] la tong lon nhat nhan duoc voi thg cuoi cung la 1 thg nao do
	f[1][1] = 0;
	f[1][2] = a[1];
	maxd[1] = 0;
	maxd[2] = a[1];
	
	FOR(i, 2, n) {//co 2 lua chon: chon a[i] hoac k chon a[i]
		f[i][1] = max(f[i-1][2]-a[i], maxd[1]);
		f[i][2] = max(f[i-1][1]+a[i], maxd[2]);
		maxd[1] = max(maxd[1], f[i][1]);
		maxd[2] = max(maxd[2], f[i][2]);
	}
	
	res = -oo;
	FOR(i, 1, n) res = max(res, max(f[i][1], f[i][2]));
	cout << res;
	return 0;
}
