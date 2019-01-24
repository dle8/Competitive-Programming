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

const ll mod = 998244353;
#define maxn 1000 + 10

ll dp[maxn][2 * maxn][4];

int main() {
	fio;
  ll n, k;
  cin >> n >> k;
  // dp[i][j][mask]: number of way to color s.t the first i columns contains j components,
  // with the last column colored as mask
  dp[1][1][0] = 1; dp[1][1][3] = 1;
  dp[1][2][1] = 1; dp[1][2][2] = 1;
  FOR(i, 2, n) {
    FOR(j, 1, k) {
      dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % mod;
      dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 1][3]) % mod;
      if (j >= 2) dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j - 2][2]) % mod;
      dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % mod;
      if (j >= 2) dp[i][j][2] = (dp[i][j][2] + dp[i - 1][j - 2][1]) % mod;
      dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % mod;
    }
  }
  ll res = 0;
  FOR(mask, 0, 3) res = (res + dp[n][k][mask]) % mod;
  cout << res;
	return 0;
}
