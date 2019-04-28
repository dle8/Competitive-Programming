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

int main() {
	fio;
  long test_cases; cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    string num;
    cin >> num;
    string res1 = "", res2 = "";
    FOR(i, 0, sz(num) - 1) {
      if (num[i] == '4') {
        res1 += '3';
        res2 += '1';
      }
      else {
        res1 += num[i];
        res2 += '0';
      }
    }
    while (res2 != "" && res2[0] == '0') res2.erase(res2.begin());
    if (res2 == "") {
      if (res1[sz(res1) - 1] == '5') {
        res1[sz(res1) - 1] = '3';
        res2 = '2';
      }
      else if (res1[sz(res1) - 1] == '0') {
        res2 = '1';
        long ptr = sz(res1) - 1;
        while (ptr >= 0 && res1[ptr] == '0') {
          res1[ptr] = '9';
          ptr--;
        }
        if (ptr >= 0) {
          if (res1[ptr] == '5') {
            res1[ptr] = '3';
            FOR(i, ptr + 1, sz(res1) - 2) res2 = '0' + res2;
            res2 = '2' + res2;
          }
          else res1[ptr] = char(res1[ptr] - 1);
        }
      }
      else {
        res1[sz(res1) - 1] = char(res1[sz(res1) - 1] - 1);
        res2 = '1';
      }
    }
    while (res1 != "" && res1[0] == '0') res1.erase(res1.begin());
    while (res2 != "" && res2[0] == '0') res2.erase(res2.begin());
    cout << "Case #" << current_test << ": " << res1 << " " << res2 << '\n';
  }
	return 0;
}
