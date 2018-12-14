#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxn 1000+10

typedef long long ll;

using namespace std;

ll f[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long test_cases, m, n, k;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		memset(f, 0, sizeof(f));
		
		cin >> m >> n >> k;
		FOR(i, 0, m) f[i][0] = 1;
		FOR(i, 0, n) f[0][i] = 1;
		FOR(i, 1, m) {
			FOR(j, 1, n) {
				f[i][j] = (f[i][j] + f[i-1][j])%k;
				f[i][j] = (f[i][j] + f[i][j-1])%k;
			}
		}
		
		cout << f[m][n] << "\n";	
	}
	return 0;
}
