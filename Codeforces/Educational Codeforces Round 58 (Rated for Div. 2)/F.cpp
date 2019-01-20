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

#define maxn 400 + 10
#define maxm 250000 + 10
vector<pll> v[maxn][maxn];
long a[maxn], dp[maxn][maxn], pos[maxn][maxn];

int main() {
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

	fio;
  long n, m;
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, m) {
    long s, f, c, r;
    cin >> s >> f >> c >> r;
    v[s][r + 1].pb({f, c});
  }
  ll res = 0;
  FOR(i, 1, n - 1) {
    FOR(j, i + 1, n) dp[j][1] = a[j] - a[i], pos[i][j] = dp[j][1];
    FOR(j, 0, sz(v[i][1]) - 1) res = max(res, 1LL * dp[v[i][1][j].fi][1] * v[i][1][j].se);
  }
  FOR(i, 1, n - 1) {
    FOR(j, i + 1, n) dp[j][1] = pos[i][j];
    FOR(k, 2, n + 1) {
      long ptr = i;
      FOR(j, i + 1, n) {
        while (ptr < j && (max(dp[ptr][k - 1], a[j] - a[ptr]) > max(dp[ptr + 1][k - 1], a[j] - a[ptr + 1]))) ptr++;
        dp[j][k] = max(dp[ptr][k - 1], a[j] - a[ptr]);
      }
      FOR(j, 0, sz(v[i][k]) - 1) res = max(res, 1LL * dp[v[i][k][j].fi][k] * v[i][k][j].se);
    }
  }
  cout << res;

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	return 0;
}
