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

ll POW(ll x, long y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll half = POW(x, y / 2);
	if (y % 2 ==0) return half * half;
	return half * half * x;
}

int main() {
	fio;

	long test_case;
	ll n;
	cin >> test_case;
	FOR(current_test, 1, test_case) {
		cin >> n;
		ll x = max(ll(POW(n, 1/double(4))), 1);
		while (POW((x + 1) * (x + 2), 2) <= (4 * n)) x++;
		if (POW(x * (x + 1), 2) == (4 * n)) {
			cout << 1 << " " << x << '\n';
			continue;
		}

		ll add = (POW((x + 1) * (x + 2), 2) - (4 * n)) / 4;
		ll subtract = (4 * n - POW(x * (x + 1), 2)) / 4;

		// cout << n << " " << add << " " << subtract << '\n';
		if (add <= subtract) {
			cout << 0 << " " << add << " " << x + 1 << '\n';
		}
		else cout << 0 << " " << -subtract << " " << x << '\n';
	}

	return 0;
}
