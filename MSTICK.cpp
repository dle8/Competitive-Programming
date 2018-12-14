/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define fi first
#define se second

using namespace std;

typedef pair<long, long> pll;

#define maxm 5000 + 10
pll wood[maxm];
long f[maxm];

bool cmp(const pll &x, const pll &y) {
	return (x.fi < y.fi || (x.fi == y.fi && x.se > y.se)); // dau >= o day se lam bai bi TLE
}

int main() {
	fio;

	long test_case, n;
	cin >> test_case;
	FOR(current_test, 1, test_case) {
		cin >> n;
		FOR(i, 1, n) {
			cin >> wood[i].fi >> wood[i].se;
		}

		sort(wood + 1, wood + 1 + n, &cmp);

		memset(f, 0, sizeof(f));
		f[1] = wood[1].se;
		long lengthF = 1;

		FOR(i, 2, n) {
			long d = 1;
			long c = lengthF;

			while (d <= c) {
				long mid = (d + c) / 2;
				if (f[mid] <= wood[i].se) c = mid - 1;
				else d = mid + 1;
			}

			long index = d;
			if (index == lengthF + 1) {
				lengthF++;
				index = lengthF;
			}

			if (f[index] < wood[i].se) f[index] = wood[i].se;
		}

		cout << lengthF << '\n';
	}

	return 0;
}
