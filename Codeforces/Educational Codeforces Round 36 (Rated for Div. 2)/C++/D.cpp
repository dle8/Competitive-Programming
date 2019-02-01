/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

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

#define maxn 500 + 10
bool check[maxn], foundCycle;
vector<long> neighbor[maxn];
long parent[maxn], tend, start;

void dfs(long u, long cond1, long cond2) {
  check[u] = true;
  // cout << u << '\n';
  FOR(i, 0, sz(neighbor[u]) - 1) {
    if (foundCycle) return;
    long v = neighbor[u][i];
    if (u == cond1 && v == cond2) continue;
    if (!check[v] && parent[v] == 0) {
      parent[v] = u;
      dfs(v, cond1, cond2);
      if (foundCycle) return;
    }
    else if (check[v]) {
      foundCycle = true;
      tend = u;
      start = v;
    }
    if (foundCycle) return;
  }
  check[u] = false;
}

int main() {
	fio;
  long n, m; cin >> n >> m;
  FOR(i, 1, m) {
    long u, v; cin >> u >> v;
    neighbor[u].pb(v);
  }
  foundCycle = false;
  memset(check, false, sizeof(check));
  FOR(i, 1, n) if (parent[i] == 0) {
    parent[i] = -1;
    dfs(i, 0, 0);
  }
  if (!foundCycle) return cout << "YES", 0;
  vector<long> path;
  while (tend != start) {
    path.pb(tend);
    tend = parent[tend];
  }
  path.pb(start);
  path.pb(path[0]);
  REP(i, sz(path) - 1, 1) {
    memset(check, false, sizeof(check));
    memset(parent, 0, sizeof(parent));
    foundCycle = false;
    FOR(j, 1, n) if (parent[j] == 0) {
      parent[j] = -1;
      dfs(j, path[i], path[i - 1]);
    }
    if (!foundCycle) return cout << "YES", 0;
  }
  cout << "NO";
	return 0;
}
