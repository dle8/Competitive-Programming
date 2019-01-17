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

#define maxn 2000
pllll h[maxn], pw[maxn];
long bad[maxn], k, check[300];
string s, alphabet;

ll max(ll a, ll b) { return (a >= b) ? a : b; }

const pllll mod = pllll(1000000009, 1007050321);
const pllll base = pllll(337, 337);

pllll operator % (const pllll &a, const pllll &b) {
	return pllll(a.fi % b.fi, a.se % b.se);
}

pllll operator * (const pllll &a, const pllll &b) {
	return pllll(a.fi * b.fi, a.se * b.se) % mod;
}

pllll operator + (const pllll &a, const pllll&b) {
	return pllll(a.fi + b.fi, a.se + b.se) % mod;
}

pllll operator - (const pllll &a, const pllll &b) {
	return (pllll(a.fi - b.fi, a.se - b.se) % mod + mod) % mod;
}

pllll get_hash(long l, long r) {
	return h[r] - h[l - 1] * pw[r - l + 1];
}

ostream& operator << (ostream &os, pllll x) {
	return os << x.fi << " " << x.se << '\n';
}

int main() {
	fio;
	cin >> s; cin >> alphabet; cin >> k;
	FOR(i, 0, 25) if (alphabet[i] == '0') check[i + 97] = 1;
	pw[0] = pllll(1, 1);
	FOR(i, 1, 2000) pw[i] = pw[i - 1] * base;
	FOR(i, 1, s.size()) h[i] = h[i - 1] * base + pllll(s[i - 1], s[i - 1]);
	memset(bad, 0, sizeof(bad));
	bad[0] = 0;
	FOR(i, 1, s.size()) bad[i] = bad[i - 1] + ((check[s[i - 1]] == 1) ? 1 : 0);
	set<pllll> myset;
	FOR(i, 1, s.size())
	FOR(j, i, s.size()) {
		if (bad[j] - bad[i - 1] > k) break;
		myset.insert(get_hash(i, j));
	}

	cout << myset.size();
	return 0;
}
