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
const long inf = 1e9;
char s[maxn];
long dp[maxn][maxn];

int main() {
	fio;
	long n; cin >> n;
	FOR(i, 1, n) cin >> s[i];
	FOR(i, 1, n) FOR(j, 1, n) dp[i][j] = ((i > j) ? 0 : inf);
	FOR(i, 1, n) dp[i][i] = 1;
	REP(i, n - 1, 1) FOR(j, i + 1, n) {
		FOR(k, i, j) {
			if (s[k] == s[j]) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
			}
			else dp[i][j] = min(dp[i][j], dp[i][k] + 1 + dp[k + 1][j - 1]);
		}
	}
	cout << dp[1][n];
	return 0;
}
