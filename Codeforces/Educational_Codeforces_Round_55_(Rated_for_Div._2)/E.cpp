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

#define maxn 500000 + 10
long tcount[maxn], a[maxn], f[maxn], pre[maxn], n, c, res;

int main() {
	fio;

  cin >> n >> c;
  FOR(i, 1, n) cin >> a[i];

  REP(i, n, 1) {
    tcount[i] = tcount[i + 1];
    if (a[i] == c) tcount[i]++;
  }

  res = 1;
  FOR(i, 1, n) {
    f[i] = max(f[pre[a[i]]], f[pre[c]]) + 1;
    pre[a[i]] = i;
    res = max(res, f[i] + tcount[i + 1]);
  }

  cout << res;

	return 0;
}
