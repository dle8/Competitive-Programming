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

const pllll mod = pllll(1000000009, 1007050321);
const pllll base = pllll(337, 337);

long n, m, c0, c1;
string s, t;
pllll h[1000006], pw[1000006];

pllll operator % (const pllll&a, const pllll&b) {
	return pllll(a.fi % b.fi, a.se % b.se);
}

pllll operator * (const pllll&a, const pllll&b) {
	return pllll(a.fi * b.fi, a.se * b.se) % mod;
}

pllll operator + (const pllll&a, const pllll&b) {
	return pllll(a.fi + b.fi, a.se + b.se) % mod;
}

pllll operator - (const pllll&a, const pllll&b) {
	return (pllll(a.fi - b.fi, b.se - b.se) % mod + mod) % mod;
}

pllll get_hash(long l, long len) {
	return h[l + len - 1] - h[l - 1] * pw[len];
}

long chk(long len) { // the maximum size of len is 2 so time complexity is O(2m)
	if (1LL * len * c0 >= m) return 0;
	if ((m - len * c0) % c1 != 0) return 0;
	long len1 = (m - len * c0) / c1;
	pllll key0 = get_hash(1, len);
	pllll key1 = pllll(-1, -1);
	long ptr = 1;
	FOR(i, 0, n - 1) {
		if (s[i] == '0') {
			if (get_hash(ptr, len) != key0) return 0;
			ptr += len;
		}
		else {
			if (key1.fi == -1) key1 = get_hash(ptr, len1);
			else if (get_hash(ptr, len1) != key1) return 0;
			ptr += len1;
		}
	}
	if (key0 == key1) return 0;
	return 1;
}

ostream& operator << (ostream &os, pllll x) {
	return os << x.fi << " " << x.se << '\n';
}

int main() {
	fio;
	cin >> s >> t;
	n = s.size(); m = t.size();
	// have to switch because in chk() we assume that the string starts with 0 when we assign key0 = get_hash(1, len)
	if (s[0] == '1') FOR(i, 0, n - 1) if (s[i] == '1') s[i] = '0'; else s[i] = '1';
	for (int i = 0; i < n; i++) if (s[i] == '0') c0++; else c1++;

	FOR(i, 1, m) h[i] = h[i - 1] * base + pllll(t[i - 1], t[i - 1]);
	pw[0] = pllll(1, 1);
	FOR(i, 1, m) pw[i] = pw[i - 1] * base;
	long ans = 0;
	FOR(i, 1, m - 1) ans += chk(i); // i is the length of the string r0
	cout << ans;
	return 0;
}
