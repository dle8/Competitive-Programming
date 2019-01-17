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
#define s first
#define r second
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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 100000 + 10
pll a[maxn];
long maxSum[maxn];

int main() {
	fio;

  long n, m, s, r;
  cin >> n >> m;

  FOR(i, 1, n) {
    cin >> a[i].s >> a[i].r;
  }

  sort(a + 1, a + 1 + n, [](pll x, pll y) {
    return (x.s < y.s || (x.s == y.s && x.r > y.r));
  });

  long current = 0, sum = 0, tcount = 0, res = 0;
  FOR(i, 1, n) {
    if (a[i].s != a[current].s) {
      current = i;
      sum = 0;
      tcount = 0;
    }
    sum += a[i].r;
    tcount++;
    if (sum > 0) {
      maxSum[tcount] += sum;
      res = max(res, maxSum[tcount]);
    }
  }

  cout << res;
	return 0;
}
