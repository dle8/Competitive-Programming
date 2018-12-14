/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
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

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 100+10
#define oo 1e18

ll d[maxn][2 * maxn];
long n, m, tcount[maxn][2 * maxn];

void floyd() {
  FOR(u, 1, n)
  FOR(v, 1, 2 * n) {
      tcount[u][v] = 1;
  }

  FOR(k, 1, n)
  FOR(u, 1, n)
  FOR(v, 1, 2 * n) {
    long temp1 = d[u][v]/(double)tcount[u][v];
    long temp2= d[u][k]/(double)tcount[u][k];
    long temp3 = d[k][v]/(double)tcount[k][v];
    if (temp1 - temp2 - temp3 > eps) {
      d[u][v] = d[u][k] + d[k][v];
      tcount[u][v] = tcount[u][k] + tcount[k][v];
    }
    else if (0.0 < temp1 - temp2 - temp3 && temp1 - temp2 - temp3 < eps) {
      tcount[u][v] = max(tcount[u][v], tcount[u][k] + tcount[k][v]);
    }
  }
}

int main() {
	fio;
  long u, v, c, test_cases;

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // cin >> test_cases;
  test_cases = 1;
  FOR(current_test, 1, test_cases) {
    cin >> n >> m;
    memset(d, 0, sizeof(d));
    memset(tcount, 0, sizeof(tcount));

    FOR(u, 1, n)
    FOR(v, 1, 2 * n) {
        d[u][v] = oo;
    }

    FOR(i, 1, m) {
      cin >> u >> v >> c;
      d[u][v] = min(d[u][v], c);
      d[u][v + n] = d[u][v];
    }

    floyd();

    float res = oo;

    bool flag = false;
    FOR(u, 1, n) {
      if (d[u][u + n] < oo && d[u][u+n]) flag = true;
      else continue;
      if (d[u][u + n]/(float)(tcount[u][u + n]) - res < eps)
        res = d[u][u + n]/(float)(tcount[u][u + n]);
    }
    if (flag) printf("%.2f\n", res);
    else cout << -1 << "\n";
  }
  // fclose(stdin);

	return 0;
}
