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

#define oo 1000000000
#define maxn 200000 + 10
long a[maxn], sl[maxn], ans[maxn];

bool cmp(const long&x, const long&y) {
	return sl[x] < sl[y];
}

int main() {
	fio;

	long n, k;
	cin >> n >> k;

	set<long> mset;
	FOR(i, 1, n) {
		cin >> a[i];
		sl[a[i]]++;
	}

	// sort(a + 1, a + 1 + n, &cmp);

	sort(a + 1, a + 1 + n, [](long x, long y) {
		return sl[x] < sl[y];
	});

	FOR(i, 1, n) mset.insert(a[i]);

	long d = 1;
	long c = n;

	while (d <= c) {
		long mid = (d + c) / 2;

		long tcount = 0;
		for (auto iter = mset.begin(); iter != mset.end(); iter++) {
			tcount += (sl[*iter] / mid);
		}

		if (tcount >= k) {
			d = mid + 1;
			long index = 0;
			for (auto iter = mset.begin(); iter != mset.end(); iter++) {
				FOR(i, 1, sl[*iter] / mid) {
					if (index + 1 > k) break;
					ans[++index] = *iter;
				}
			}
		}
		else c = mid - 1;
	}

	FOR(i, 1, k) cout << ans[i] << " ";

	return 0;
}
