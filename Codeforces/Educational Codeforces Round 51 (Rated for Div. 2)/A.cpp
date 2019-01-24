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

bool isDigit(char c) {
  return (48 <= c && c <= 57);
}

bool isLower(char c) {
  return (97 <= c && c <= 122);
}

bool isUpper(char c) {
  return (65 <= c && c <= 90);
}

int main() {
	fio;

  long test_cases;
  string s;
  cin >> test_cases;
  FOR(current_test, 1,  test_cases) {
    cin >> s;
    long upper = 0, lower = 0, digit = 0;
    FOR(i, 0, sz(s) - 1) {
      if (isDigit(s[i])) digit++;
      else if (isUpper(s[i])) upper++;
      else lower++;
    }
    if (digit > 0 && upper > 0 && lower > 0) {
      cout << s << '\n';
      continue;
    }
    else if ((digit == 0 && upper == 0) || (digit == 0 && lower == 0) || (lower == 0 && upper == 0)) {
      long index = 0;
      if (digit == 0) s[index++] = '1';
      if (upper == 0) s[index++] = 'A';
      if (lower == 0) s[index++] = 'a';
    }
    else {
      if (digit == 1 || upper == 1 || lower == 1) {
        FOR(i, 0, sz(s) - 1) {
          if (isDigit(s[i]) && digit > 1) {
            if (upper == 0) s[i] = 'A';
            if (lower == 0) s[i] = 'a';
            break;
          }
          else if (isLower(s[i]) && lower > 1) {
            if (digit == 0) s[i] = '1';
            if (upper == 0) s[i] = 'A';
            break;
          }
          else if (isUpper(s[i]) && upper > 1) {
            if (digit == 0) s[i] = '1';
            if (lower == 0) s[i] = 'a';
            break;
          }
        }
      }
      else {
        if (digit == 0) s[0] = '1';
        if (upper == 0) s[0] = 'A';
        if (lower == 0) s[0] = 'a';
      }
    }
    cout << s << '\n';
  }

	return 0;
}
