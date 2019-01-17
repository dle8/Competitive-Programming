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
#define sz(x) int(x.size())
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
const ll mod = 1000000007;
ll ft[maxn];
long n;

void update(long i, ll val) {
  for (; i <= n; i += (i & (-i))) ft[i] = (ft[i] + val) % mod;
}

ll sum(long i) {
  ll total = 0;
  for (; i > 0; i -= (i& (-i))) total = (total + ft[i]) % mod;
  return total;
}

ll sum(long d, long c) {
  return (sum(c) - sum(d - 1)) % mod;
}

int main() {
	fio;
  string s; cin >> s;
  ll res = 0;
  n = sz(s);
  long lastB = 0;
  FOR(i, 0, n - 1) {
    long tmp = 0;
    if (s[i] == 'a') {
      tmp++;
      res = (res + (tmp + sum(lastB))) % mod;
      update(i + 1, tmp + sum(lastB));
    }
    else if (s[i] == 'b') lastB = i + 1;
  }
  cout << res;
	return 0;
}
