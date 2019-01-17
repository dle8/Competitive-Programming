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

struct edge {
  ll u, v, c;
};

#define inf 1000000000000000000
#define maxn 200000 + 10
vector<edge> edges;
ll lab[maxn], a[maxn];

ll getRoot(ll u) {
  return (lab[u] < 0 ? u : (lab[u] = getRoot(lab[u])));
}

bool dsu(ll u, ll v) {
  ll r1 = getRoot(u);
  ll r2 = getRoot(v);
  if (r1 == r2) return false;
  if (r1 != r2) {
    if (lab[r1] == lab[r2]) {
      lab[r1]--;
      lab[r2] = r1;
    }
    else if (lab[r1] < lab[r2]) lab[r2] = r1;
    else if (lab[r1] > lab[r2]) lab[r1] = r2;
    return true;
  }
}

int main() {
	fio;
  ll n, m, u, v, c;
  cin >> n >> m;
  ll minWeight = inf;
  ll tmp;
  FOR(i, 1, n) {
    cin >> a[i];
    lab[i] = -1;
    if (minWeight > a[i]) {
      minWeight = a[i];
      tmp = i;
    }
  }
  FOR(i, 1, m) {
    cin >> u >> v >> c;
    edges.pb({u, v, c});
  }
  FOR(i, 1, n) if (i != tmp) edges.pb({tmp, i, a[tmp] + a[i]});
  sort(edges.begin(), edges.end(), [](edge x, edge y){
    return x.c < y.c;
  });
  ll ans = 0;
  for (auto e: edges) {
    if (dsu(e.u, e.v)) ans += e.c;
  }
  cout << ans;
	return 0;
}
