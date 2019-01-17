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

#define maxn 200000 + 10

pll a[maxn];
long ans[maxn];

bool cmp(const pll&x, const pll&y) {
	return (x.fi < y.fi);
}

int main() {
	fio;

	long n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].fi;
		a[i].se = i;
	}

	sort(a + 1, a + 1 + n, &cmp);

	ll sum = 0;
	FOR(i, 1, n - 1) {
		sum += a[i].fi;
	}

	long index = 0;
	REP(i, n, 1) {
		if (i == n && i > 1) {
			if (sum - a[n - 1].fi == a[n - 1].fi) ans[++index] = a[i].se;
		}
		else {
			if (sum - a[i].fi == a[n].fi) ans[++index] = a[i].se;
		}
	}

	cout << index << '\n';
	FOR(i, 1, index) cout << ans[i] << " ";

	return 0;
}
