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

#define oo 1000000000
#define maxn 100 + 10
long a[4 * maxn], c, n;

bool cmp(const pll&x, const pll&y) {
	return (x.fi < y.fi);
}

long bs(long arr[], long length, long key) {
	long l = 1;
	long r = length;
	long mid;
	while (l<=r) {
		mid = (l+r)/2;
		if (arr[mid] >= key) r = mid -1;
		else l = mid + 1;
	}
	return l;
}

long LIS() {
	long f[4 * maxn];
	memset(f, 0, sizeof(f));

	f[1] = a[1];
	long lengthF = 1; // number of columns

	FOR(i, 2, (c * n)) {
		long place = bs(f, lengthF, a[i]);
		if (place == lengthF + 1) {
			f[++lengthF] = a[i];
		}
		else if (f[place] > a[i]) f[place] = a[i];
	}

	return lengthF;
}

int main() {
	fio;

	long col, value;
	cin >> c >> n;

	vector<vector<pll>> color(5);

	FOR(i, 1, (c * n)) {
		cin >> col >> value;
		color[col].pb(mp(value, i));
	}

	FOR(i, 1, c) {
		sort(color[i].begin(), color[i].end(), &cmp);
	}

	vector<long> colorOrder;
	FOR(i, 1, c) colorOrder.pb(i);

	long res = oo;
	// iterate through all possible order in which colors can take in an array
	do {
		// danh so lai mang cac card ban dau dua tren order cua cac mau
		long index = 0;
		FOR(i, 0, c - 1) {
			FOR(j, 0, int(color[colorOrder[i]].size()) - 1) {
				a[color[colorOrder[i]][j].se] = ++index;
			}
		}

		res = min(res, (c * n) - LIS());

	} while (next_permutation(colorOrder.begin(), colorOrder.end()));

	cout << res;
	return 0;
}
