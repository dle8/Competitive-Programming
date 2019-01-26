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
long a[maxn];
char place[maxn];
pll range[maxn];

int main() {
	fio;
  long n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n - 1) cin >> place[i];
  long cnt = 0;
  place[n] = '0';
  FOR(i, 1, n) {
    if (place[i] == '1' && place[i - 1] != '1') range[++cnt].fi = i;
    else if (place[i] != '1' && place[i - 1] == '1') range[cnt].se = i;
  }
  FOR(i, 1, cnt) sort(a + range[i].fi, a + range[i].se + 1);
  bool ok = true;
  FOR(i, 1, n) if (a[i] != i) {
    ok = false;
    break;
  }
  cout << ((ok) ? "YES" : "NO");
	return 0;
}
