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
//
// ll gcd(ll a, ll b, ll &x, ll &y) {
//     if (a == 0) {
//         x = 0; y = 1;
//         return b;
//     }
//     ll x1, y1;
//     ll d = gcd(b%a, a, x1, y1);
//     x = y1 - (b / a) * x1;
//     y = x1;
//     return d;
// }

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define oo 1000000000

int main() {
	fio;

	long test_cases, n, x, y, d;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> x >> y >> d;
		if (x == y) {
			cout << 0 << '\n';
			continue;
		}
		if (abs(y - x) % d == 0) {
			cout << abs(y - x) / d << '\n';
			continue;
		}

		long tmp1, tmp2;
		tmp1 = abs(n - x) / d;
		if (abs(n - x) % d != 0) tmp1++;
		if (abs(n - y) % d != 0) tmp1 = oo;
		else tmp1 += abs(n - y) / d;
		tmp2 = abs(x - 1) / d;
		if (abs(x - 1) % d != 0) tmp2++;
		if (abs(y - 1) % d != 0) tmp2 = oo;
		else tmp2 += abs(y - 1) / d;
		if (tmp1 == oo && tmp2 == oo) cout << -1 << '\n';
		else cout << min(tmp1, tmp2) << '\n';
	}

	return 0;
}
