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

inline ll common(ll u, ll v, ll l, ll r) {
  if (v < l || r < u) return 0;
  if (l <= u) return (r - u + 1);
  return (v - l + 1);
}

int main() {
	fio;

  string s, tmp, res;
  long n;

  cin >> n;
  cin >> s;

  res = "";

  if (n != 1) {
    FOR(i, 0, n - 2) {
      if (s[i] > s[i + 1]) {
        tmp = s;
        tmp.erase(tmp.begin() + i);
        return cout << tmp, 0;
      }
    }
    s.erase(s.begin() + int(s.length()) - 1);
    return cout << s, 0;
  }

  cout << res;

	return 0;
}
