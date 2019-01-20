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
#define maxn 200000 + 10
map<ll, ll> pos;
long a[maxn], n;
pll seg[maxn];

int main() {
	fio;
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  REP(i, n, 1) if (pos[a[i]] == 0) pos[a[i]] = i;
  long ptr1 = 1, ptr2 = 1, cnt = 0;
  while (true) {
    while (ptr1 <= n && pos[a[ptr1]] == ptr1) ptr1++;
    if (ptr1 > n) break;
    long last = pos[a[ptr1]], tmp = 0;
    FOR(i, ptr1 + 1, n + 1) {
      if (i > last) {
        seg[++cnt] = {ptr1, last};
        ptr1 = i;
        break;
      }
      else tmp = last + 1;
      last = max(last, pos[a[i]]);
    }
    ptr1 = max(ptr1, tmp);
  }
  ll res = 1;
  ptr1 = 2;
  FOR(i, 1, cnt) {
    FOR(j, ptr1, seg[i].fi) res = (res * 2) % mod;
    ptr1 = seg[i].se + 1;
  }
  FOR(i, ptr1, n) res = (res * 2) % mod;
  cout << res;
	return 0;
}
