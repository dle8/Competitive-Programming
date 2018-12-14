#include <bits/stdc++.h>
#define maxmn 100000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

long a[maxmn], vest[maxmn], match[maxmn], n, m, x, y;
bool check[maxmn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) cin >> vest[i];
	
	long res = 0;
	long i = 0;
	long j = 1;
	memset(check, true, sizeof(check));
	while (i<n) {
		i++;
		if (a[i]+y<vest[j]) continue;
		while ((a[i]-x>vest[j] || !check[j]) && j<m) j++;
		if (j>m) continue;
		if (a[i]-x<=vest[j] && vest[j]<=a[i]+y && check[j]) {
			match[i] = j;
			res++;
			check[j] = false;
		}
	}	

	cout << res << "\n";
	FOR(i, 1, n)
	if(match[i]!=0) cout << i << " " << match[i] << "\n";
	return 0;
}
