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

#define maxm 20000 + 10
pll doll[maxm];
long f[maxm];

bool cmp(const pll &x, const pll &y) {
	return (x.fi < y.fi || (x.fi == y.fi && x.se > y.se));
}

int main() {
	fio;

	long test_case, m;
	cin >> test_case;
	FOR(current_test, 1, test_case) {
		cin >> m;
		FOR(i, 1, m) {
			cin >> doll[i].fi >> doll[i].se;
		}

		sort(doll + 1, doll + 1 + m, &cmp);

		memset(f, 0, sizeof(f));
		f[1] = doll[1].se;
		long lengthF = 1;

		FOR(i, 2, m) {
			long d = 1;
			long c = lengthF;

			while (d <= c) {
				long mid = (d + c) / 2;
				if (f[mid] >= doll[i].se) d = mid + 1;
				else c = mid - 1;
			}

			long index = d;
			if (index == lengthF + 1) {
				lengthF++;
				index = lengthF;
			}

			if (f[index] <= doll[i].se) f[index] = doll[i].se;
		}

		cout << lengthF << '\n';
	}

	return 0;
}
