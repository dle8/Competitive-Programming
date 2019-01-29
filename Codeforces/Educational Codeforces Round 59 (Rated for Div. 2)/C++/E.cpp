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
inline ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 100 + 10
ll dp[maxn][maxn][maxn], maxCon[maxn], a[maxn];
char s[maxn];

int main() {
	fio;
  long n; cin >> n;
  FOR(i, 1, n) cin >> s[i];
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) maxCon[i] = a[i];
  FOR(i, 2, n) FOR(j, 0, i - 1) maxCon[i] = max(maxCon[i], maxCon[j] + maxCon[i - j]);
  FOR(i, 1, n) dp[i][i][0] = maxCon[1];
  FOR(i, 2, n) FOR(j, 1, i - 1) {
    ll cnt = 0;
    FOR(t, j, i - 1) if (s[t] == s[i]) cnt++; // number of character than can erase at the time with s[i]
    FOR(k, 0, cnt) {
      if (k == 0) {
        ll maxSeg = 0;
        FOR(u, 0, 100) maxSeg = max(maxSeg, dp[i - 1][j][u]);
        dp[i][j][k] = max(dp[i][j][k], maxCon[1] + maxSeg);
        continue;
      }
      ll tmp = 0;
      FOR(t, j, i - 1) if (s[t] == s[i]) {
        tmp++;
        if (k > tmp) continue;
        ll maxSeg = 0;
        FOR(u, 0, 100) maxSeg = max(maxSeg, dp[i - 1][t + 1][u]);
        dp[i][j][k] = max(dp[i][j][k], dp[t][j][k - 1] - maxCon[k] + maxCon[k + 1] + maxSeg);
      }
    }
  }
  ll res = 0;
  FOR(i, 0, 100) res = max(res, dp[n][1][i]);
  cout << res;
	return 0;
}
