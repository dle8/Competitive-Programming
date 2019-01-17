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
#define maxn 200000 + 10
bool check[maxn];
vector<vl> neighbor(maxn);
vl kid;

int main() {
	fio;
  long n, x, y;
  cin >> n;
  FOR(i, 1, n) {
    long u, v;
    cin >> u >> v;
    neighbor[i].pb(u);
    neighbor[i].pb(v);
  }
  x = neighbor[1][0];
  y = neighbor[1][1];
  bool ok1 = false, ok2 = false;
  FOR(i, 0, 1) {
    if (neighbor[x][i] == y) ok1 = true;
    if (neighbor[y][i] == x) ok2 = true;
  }
  kid.pb(1);
  check[1] = true;
  if (ok1) {
    kid.pb(x);
    kid.pb(y);
  }
  else {
    kid.pb(y);
    kid.pb(x);
  }
  check[x] = true;
  check[y] = true;
  long index = 1;
  while (true) {
    bool stop = true;
    FOR(i, 0, 1) if (!check[neighbor[kid[index]][i]]) {
      check[neighbor[kid[index]][i]] = true;
      kid.pb(neighbor[kid[index]][i]);
      stop = false;
    }
    if (stop) break;
    index++;
  }
  FOR(i, 0, n - 1) cout << kid[i] << " ";
	return 0;
}
