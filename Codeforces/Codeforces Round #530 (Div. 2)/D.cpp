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
const ll inf = 1e18;
#define maxn 100000 + 10
vector<vector<ll>> child(maxn);
vector<long> path;
bool flag;
ll minWeight[maxn], s[maxn], h[maxn], res;

void dfs(ll u, ll height) {
  h[u] = height;
  if (height % 2 != 0) {
    if (!path.empty() && s[u] < path.back()) flag = true;
    path.pb(s[u]);
  }
  FOR(i, 0, sz(child[u]) - 1) {
    ll v = child[u][i];
    minWeight[u] = min(minWeight[u], s[v]);
    dfs(v, height + 1);
  }
  if (height % 2 != 0) path.pop_back();
}

void calc(ll u) {
  FOR(i, 0, sz(child[u]) - 1) {
    ll v = child[u][i];
    if (h[v] % 2 == 0) {
      if (minWeight[v] == inf) s[v] = s[u];
      else s[v] = minWeight[v];
    }
    res += (s[v] - s[u]);
    calc(v);
  }
}

int main() {
	fio;
  long n;
  cin >> n;
  FOR(i, 2, n) {
    long u;
    cin >> u;
    child[u].pb(i);
  }
  FOR(i, 1, n) cin >> s[i];
  flag = false;
  FOR(i, 1, n) minWeight[i] = inf;
  dfs(1, 1);
  res = s[1];
  calc(1);
  if (flag) return cout << -1, 0;
  cout << res;
	return 0;
}
