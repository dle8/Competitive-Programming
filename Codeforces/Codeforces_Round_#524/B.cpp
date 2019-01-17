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

int main() {
	fio;

	long q, l, r;
	cin >> q;
	FOR(i, 1, q) {
		cin >> l >> r;
		if (l == r) {
			cout << ((l % 2 == 0) ? l : -l) << '\n';
			continue;
		}
		ll res = 0;
		long c;
		if (l % 2 == 0) {
			long d = l;
			if (r % 2 == 0) c = r - 1;
			else c = r;

			res = -1 * ((c - d + 1) / 2);
			res += ((r % 2 == 0) ? r : 0);
		}
		else {
			long d = l;
			if (r % 2 == 0) c = r;
			else c = r - 1;

			res = 1 * ((c - d + 1) / 2);
			res += ((r % 2 == 0) ? 0 : -r);
		}

		cout << res << '\n';
	}

	return 0;
}
