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

/* tach xau
string str = "Hello World"; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

struct node {
  long fi, se, order;
};

#define maxn 100000 + 10
node p[maxn];
long res[maxn];

int main() {
	fio;
  long test_cases, n;
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> n;
    FOR(i, 1, n) {
      cin >> p[i].fi >> p[i].se;
      p[i].order = i;
    }
    sort(p + 1, p + 1 + n, [](const node&x, const node&y){
      return (x.fi < y.fi || (x.fi == y.fi && x.se > y.se));
    });
    long last = p[1].se, ptr = -1;
    FOR(i, 2, n) {
      if (last < p[i].fi) {
        ptr = i;
        break;
      }
      last = max(last, p[i].se);
    }
    if (ptr == -1) {
      cout << -1 << '\n';
      continue;
    }
    FOR(i, 1, ptr - 1) res[p[i].order] = 1;
    FOR(i, ptr, n) res[p[i].order] = 2;
    FOR(i, 1, n) cout << res[i] << " ";
    cout << '\n';
  }

	return 0;
}
