/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

#define maxn 30000 + 10
#define oo 1000000000
long it[4 * maxn], lazy[4 * maxn];

bool cmp(const pll&x, const pll&y) {
	return x.fi < y.fi;
}

void update(long cs, long u, long v, long l, long r, long val) {
	if (r < u || v < l) return;
	if (lazy[cs] == val) return;
	if (lazy[cs] != 0) { // there is an pending update
		it[cs] += (v - u + 1) * lazy[cs];
		if (u != v) {
			lazy[2 * cs] = lazy[cs];
			lazy[2 * cs + 1] = lazy[cs];
		}
		lazy[cs] = 0;
	}
	if (l <= u && v <= r) {
		lazy[cs] = val;
		return;
	}

	long mid = (u + v) / 2;
	update(2 * cs, u, mid, l, r, val);
	update(2 * cs + 1, mid + 1, v, l, r, val);

	if (lazy[2 * cs] != 0) it[cs] += it[2 * cs] * lazy[2 * cs];
	else it[cs] += it[2 * cs];
	if (lazy[2 * cs + 1] != 0) it[cs] += it[2 * cs + 1] * lazy[2 * cs + 1];
	else it[cs] += it[2 * cs + 1];
}

long rangeSum(long cs, long u, long v, long l, long r) {
	if (v < l || r < u) return 0;
	if (l <= u && v <= r) {
		if (lazy[cs] == 0) return it[cs];
		return it[cs] * lazy[cs];
	}

	long mid = (u + v) / 2;
	if (lazy[cs] != 0) {
		if (u != v) {
			lazy[2 * cs] = lazy[cs];
			lazy[2 * cs + 1] = lazy[cs];
		}
		lazy[cs] = 0;
	}

	return rangeSum(2 * cs, u, mid, l, r) + rangeSum(2 * cs + 1, mid + 1, v, l, r);
}

int main() {
	fio;

	long n, x1, x2, y1, y2;
	cin >> n;

	vector<pll> empty;
	vector<vector<pll>> columnsPos(maxn + 1, empty);
	vector<vector<pll>> columnsNeg(maxn + 1, empty);

	FOR(i, 1, n) {
		cin >> x1 >> y1 >> x2 >> y2;
		columnsPos[x1].pb(mp(y1, y2));
		columnsNeg[x2 + 1].pb(mp(y1, y2));
	}

	ll totalArea = 0;
	FOR(i, 1, 30000) {
		FOR(j, 0, int(columnsPos[i].size()) - 1) {
			update(1, 1, 30000, columnsPos[i][j].fi, columnsPos[i][j].se, 1);
		}

		FOR(j, 0, int(columnsNeg[i].size()) - 1) {
			update(1, 1, 30000, columnsNeg[i][j].fi, columnsNeg[i][j].se, -1);
		}

		totalArea += rangeSum(1, 1, 30000, 1, 30000);
	}

	cout << totalArea;

	return 0;
}
