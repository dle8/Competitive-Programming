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

ll cut(ll x) { // turn 2^x -> 2^0
	ll res = 0; ll tmp = 1;
	while (x > 0) {
		res += tmp;
		tmp *= 4;
		x--;
	}
	return res;
}

int main() {
	fio;

	long test_cases;
	ll n, k, side;
	vector<pllll> v;
	cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> n >> k;
		ll tcount = 0, tmp = k;
		side = n;

		v.clear();
		bool found = false;
		FOR(i, 1, 64) {
			if (tcount + pow(2, i) - 1 <= k && side > 0) {
				tcount += (pow(2, i) - 1);
				tmp -= pow(2, i) - 1;
				if (tcount == k) found = true;
				side--;
				v.pb(mp(side, (pow(2, i) - 1) * 4 - (pow(2, i + 1) - 1)));
			}
			else break;
		}

		if (found) {
			cout << "YES " << side << '\n';
			continue;
		}

		k = tmp;

		FOR(i, 0, int(v.size()) - 1) {
			if (v[i].fi >= 64 || k == 0) {
				k = 0;
				break;
			}
			ll cutNeeded = 1LL * cut(v[i].fi) * v[i].se;
			k -= min(k, cutNeeded);
		}

		if (k == 0) cout << "YES " << side << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}
