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

#define oo 1e9
#define maxn 50000 + 10
long lazy[4 * maxn], it[4 * maxn];

void update(long index, long u, long v, long l, long r, long val) {
	if (r < u || v < l) return;
	if (l <= u && v <= r) {
		lazy[index] += val;
		return;
	}
	long mid = (u + v)/2;
	update(2 * index, u, mid, l, r, val);
	update(2 * index + 1, mid + 1, v, l, r, val);
	it[index] = max(it[2 * index] + lazy[2 * index], it[2 * index + 1] + lazy[2 * index + 1]);
}

long maxIT(long index, long u, long v, long l, long r) {
	if (r < u || v < l) return -oo;
	if (l <= u && v <= r) return it[index] + lazy[index];
	long mid = (u + v)/2;
	return max(maxIT(2 * index, u, mid, l, r), maxIT(2 * index + 1, mid + 1, v, l, r)) + lazy[index];
}

int main() {
	fio;

	long n, m, tcase, x, y, val;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> tcase >> x >> y;
		if (tcase == 0) {
			cin >> val;
			update(1, 1, n, x, y, val);
		}
		else cout << maxIT(1, 1, n, x, y) << "\n";
	}

	return 0;
}
