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
#define maxn 200000 + 10
ll a[maxn], n, k;
char s[maxn];
vector<ll> v[30];
pll interval[maxn];

int main() {
	fio;
  cin >> n >> k;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> s[i];
  long cnt = 0;
  FOR(i, 1, n) {
    if (s[i] != s[i - 1]) interval[++cnt].fi = i;
    if (s[i] != s[i + 1]) interval[cnt].se = i;
  }
  ll res = 0;
  FOR(i, 1, cnt) {
    sort(a + interval[i].fi, a + interval[i].se + 1, greater<int>());
    FOR(j, 1, min(k, interval[i].se - interval[i].fi + 1)) {
      res += a[interval[i].fi + j - 1];
    }
  }
  cout << res;
	return 0;
}
