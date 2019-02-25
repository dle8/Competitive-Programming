/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;

#define maxn 10000 + 10
#define maxk 50 + 10

const long mod = 5000000;
long dp[maxn][maxk], n, k, ft[maxn][maxk];
vector<long> v[100000 + 10];

void update(long j, long i, long val) {
	for (; j <= n; j += (j & (-j))) {
		ft[j][i] = (ft[j][i] + val) % mod;
	}
}

long sum(long j, long i) {
	long total = 0;
	for (; j > 0; j -= (j & (-j))) total = (total + ft[j][i]) % mod;
	return total;
}

int main() {
	fio;
	set<long> mset;
	long num;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> num;
		mset.insert(num);
		v[num].pb(i);
	}
	FOR(i, 1, n) dp[i][1] = 1;
	FOR(i, 2, k) {
		FORALL(iter, mset) {
			FOR(j, 0, sz(v[*iter]) - 1) {
				dp[v[*iter][j]][i] = (dp[v[*iter][j]][i] + sum(v[*iter][j] - 1, i - 1)) % mod;
			}
			FOR(j, 0, sz(v[*iter]) - 1) update(v[*iter][j], i - 1, dp[v[*iter][j]][i - 1]);
		}
	}
	long res = 0;
	FOR(i, 1, n) res = (res + dp[i][k]) % mod;
	cout << res;
	return 0;
}
