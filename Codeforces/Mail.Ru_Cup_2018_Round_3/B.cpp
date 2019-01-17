/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

#define maxm 1000 + 10
ll tcount[maxm];

int main() {
	fio;

	long n, m;
	cin >> n >> m;
	tcount[0] = n / m;
	FOR(i, 1, m - 1) {
		if (n >= i) tcount[(i * i) % m] += ((n - i) / m + 1);
	}

	ll res = 0;
	tcount[m] = tcount[0];
	FOR(i, 0, m - 1) {
		res += 1LL * tcount[i] * tcount[m - i];
	}

	cout << res;

	return 0;
}
