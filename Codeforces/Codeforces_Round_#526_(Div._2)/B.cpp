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

#define oo 1000000000000000000
#define maxn 1000 + 10
ll v[maxn], n, s;

int main() {
  fio;

  cin >> n >> s;
  ll total = 0, leastKeg = oo, sparse = 0;
  FOR(i, 1, n) {
    cin >> v[i];
    total += v[i];
    leastKeg = min(leastKeg, v[i]);
  }
  FOR(i, 1, n) sparse += (v[i] - leastKeg);
  if (total < s) return cout << -1, 0;
  if (sparse >= s) return cout << leastKeg, 0;
  s -= sparse;
  cout << leastKeg - s / n - ((s % n == 0) ? 0 : 1);
  return 0;
}
