/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9
#define sz(x) int(x.size())

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

/* tach xau
string str = "Hello World", token; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

/*
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

#ifdef _TIME
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
*/

#define maxn 5000 + 10
long ft[maxn], fence[maxn], cnt[maxn], n, q;
pll range[maxn];

void update(long i) {
	for (; i <= n; i += (i & (-i))) ft[i]++;
}

long sum(long i) {
	long total = 0;
	for (; i > 0; i -= (i & (-i))) total += ft[i];
	return total;
}

long sum(long d, long c) {
	return sum(c) - sum(d - 1);
}

int main() {
	fio;
	cin >> n >> q;
	FOR(i, 1, q) {
		cin >> range[i].fi >> range[i].se;
		fence[range[i].fi]++;
		fence[range[i].se + 1]--;
	}
	FOR(i, 1, n) {
		fence[i] += fence[i - 1];
		if (fence[i] == 2) update(i);
	}
	FOR(i, 1, q) FOR(j, range[i].fi, range[i].se) if (fence[j] == 1) cnt[i]++;
	// FOR(i, 1, q) cout << cnt[i] << " ";
	long coveredFence = 0;
	FOR(i, 1, n) if (fence[i] > 0) coveredFence++;
	long res = 0;
	FOR(i, 1, q - 1) FOR(j, i + 1, q) {
		long tmp = coveredFence;
		tmp -= (cnt[i] + cnt[j]);
		pll r1 = range[i];
		pll r2 = range[j];
		if (r1.fi > r2.fi) swap(r1, r2);
		if (r1.se >= r2.fi) {
			tmp -= sum(r2.fi, min(r1.se, r2.se));
		}
		res = max(res, tmp);
	}
	cout << res;
	return 0;
}
