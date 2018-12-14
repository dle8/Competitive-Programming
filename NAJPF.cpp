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

ll max(ll a, ll b) { return (a >= b) ? a : b; }

const pllll mod = pllll{1000000009, 1007050321};
const pllll base = pllll{863, 863};

#define maxn 1000000 + 10
string s, t;
pllll h[maxn], pw[maxn];

pllll operator % (const pllll&x, const pllll&y) {
	return pllll(x.fi % y.fi, x.se % y.se);
}

pllll operator * (const pllll&x, const pllll&y) {
	return pllll(x.fi * y.fi, x.se * y.se) % mod;
}

pllll operator + (const pllll&x, const pllll&y) {
	return pllll(x.fi + y.fi, x.se + y.se) % mod;
}

pllll operator - (const pllll&x, const pllll&y) {
	return (pllll(x.fi - y.fi, x.se - y.se) % mod + mod) % mod;
}

pllll get_hash(long l, long len) {
	return h[l + len - 1] - h[l - 1] * pw[len];
}

int main() {
	fio;
	long test_cases; cin >> test_cases;
	FOR(current_test, 1, test_cases) {
		cin >> s; cin >> t;
		if (s.size() < t.size()) {
			cout << "Not Found" << '\n';
			cout << '\n';
			continue;
		}
		pw[0] = pllll(1, 1);
		FOR(i, 1, maxn) pw[i] = pw[i - 1] * base;
		h[0] = pllll(0, 0);
		FOR(i, 1, t.size()) h[i] = h[i - 1] * base + pllll(t[i - 1], t[i - 1]);
		pllll key = get_hash(1, t.size());

		h[0] = pllll(0, 0);
		FOR(i, 1, s.size()) h[i] = h[i - 1] * base + pllll(s[i - 1], s[i - 1]);
		vi ans; ans.clear();
		FOR(i, 1, s.size() - t.size() + 1) {
			if (get_hash(i, t.size()) == key) ans.pb(i);
		}
		if (ans.size() == 0) cout << "Not Found";
		else {
			cout << ans.size() << '\n';
			FOR(i, 0, ans.size() - 1) cout << ans[i] << " ";
		}
		cout << '\n'; cout << '\n';
	}

	return 0;
}
