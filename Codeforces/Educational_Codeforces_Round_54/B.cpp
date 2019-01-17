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

bool isPrime(ll x) {
  if (x <= 1) return false;
  if (x == 2 || x == 3) return true;
  FOR(i, 2, sqrt(x)) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
	fio;

  ll n, res = 0;
  cin >> n;
  if (n == 1 || n == 0) return 0;

  if (n % 2 == 0) return cout << n / 2, 0;
  long factor = 0;
  FOR(i, 3, sqrt(n)) {
    if (n % i == 0 && isPrime(i)) {
      factor = i;
      break;
    }
  }

  if (factor == 0) return cout << 1, 0;
  return cout << 1 + (n - factor) / 2, 0;

	return 0;
}
