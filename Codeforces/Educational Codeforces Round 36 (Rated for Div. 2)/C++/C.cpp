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

#define maxn 20 + 10
#define alpha 1000 + 10
bool check[maxn];
ll sla[maxn], slb[maxn];

int main() {
	fio;
  string a, b;
  getline(cin, a);
  getline(cin, b);
  if (sz(a) < sz(b)) {
    sort(a.begin(), a.end(), greater<char>());
    cout << a;
  }
  else {
    // trg hop dac biet
    vector<char> v;
    FOR(i, 0, sz(a) - 1) {
      sla[a[i]]++;
      slb[b[i]]++;
      v.pb(a[i]);
    }
    bool equal = true;
    FOR(i, 0, sz(a) - 1) if (sla[a[i]] != slb[a[i]]) equal = false;
    if (equal) return cout << b, 0;
    string res = "";
    FOR(i, 0, sz(b) - 1) {
      ll minDiff = 1000, tmp = -1;
      FOR(j, 0, sz(a) - 1) if (!check[j] && b[i] - a[j] >= 0 && b[i] - a[j] < minDiff) {
        minDiff = b[i] - a[j];
        tmp = j;
      }
      if (a[tmp] == b[i] && i != sz(b) - 1) {
        ll index;
        FOR(j, 0, sz(v) - 1) if (v[j] == a[tmp]) index = j;
        v.erase(v.begin() + index);
        sort(v.begin(), v.end());
        string s1 = "", s2 = b.substr(i + 1);
        FOR(j, 0, sz(v) - 1) s1 += v[j];
        ll t1 = stoll(s1), t2 = stoll(s2);
        if (t1 > t2) {
          v.pb(a[tmp]);
          minDiff = 1000;
          FOR(j, 0, sz(a) - 1) if (!check[j] && b[i] - a[j] > 0 && b[i] - a[j] < minDiff) {
            minDiff = b[i] - a[j];
            tmp = j;
          }
          FOR(j, 0, sz(v) - 1) if (v[j] == a[tmp]) index = j;
          v.erase(v.begin() + index);
        }
      }
      res += a[tmp];
      check[tmp] = true;
      if (a[tmp] != b[i]) break;
    }
    v.clear();
    FOR(i, 0, sz(a) - 1) if (!check[i]) v.pb(a[i]);
    sort(v.begin(), v.end(), greater<char>());
    FOR(i, 0, sz(v) - 1) res += v[i];
    cout << res;
  }
	return 0;
}
