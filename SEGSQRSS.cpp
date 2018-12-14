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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define oo 1e18
#define maxn 100000+10
long n;
ll it[3 * maxn], sqrit[3 * maxn], add[3 * maxn], replace[3 * maxn];

void update(long index, long u, long v) {
	if (u == v) {
		sqrit[index] = pow(a[u], 2);
		it[index] = a[u];
		add[index] = 0;
		replace[index] = oo;
		return;
	}
	long mid = (u + v)/2;
	update(2 * index, u, mid);
	update(2 * index + 1, mid + 1, v);
	it[index] = it[2 * index] + it[2 * index + 1];
	sqrit[index] = sqrit[2 * index] + sqrit[2 * index + 1];
}

void update(long index, long u, long v, long l, long r, long aval, long rval) {
	if (r < u || v < l) return;
	if (l <= u && v <= r) {
		if (aval != oo) add[index] += aval;
		if (rval != oo) replace[index] = rval;
	}
	else {
		long mid = (u + v)/2;
		update(2 * index, u, mid, l, r, aval, rval);
		update(2 * index + 1, mid + 1, v, l, r, aval, rval);
	}
	if (replace[index] != oo) {
		update
	}
}

int main() {
	fio;

	long test_cases, type, q, st, nd;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		memset(sqrit, 0, sizeof(sqrit));

		cin >> n >> q;
		FOR(i, 1, n) cin >> a[i];
		update(1, 1, n);

		FOR(i, 1, q) {
			cin >> type >> st >> nd;
			if (type == 2) cout << squareSum(st, nd) << "\n";
			if (type == 1) update(1, 1, n, st, nd, x, oo);
			if (type == 0) update(1, 1, n, st, nd, oo, x);
		}
	}

	return 0;
}
